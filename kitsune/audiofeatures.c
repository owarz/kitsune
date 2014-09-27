#include "audiofeatures.h"
#include "fft.h"
#include <string.h>
#include <stdlib.h>     /* abs */
#include "debugutils/debuglog.h"
#include <stdio.h>


/*
   How is this all going to work? 
   -Extract features, one of which is total energy
   -If average energy over some period is stable, then
    
    1) See if this frame of features is similar to others.
    2) If not similar, store feature vector in memory
    3) Report this frame as being 
       a. interesting, 
       b. interesting but already observed (i.e. similar)
       c. totally fucking uninteresting (ah, blissful silence)
    4) Some other piece of code will later
 
 
    -Potential pitfalls as is:
     
       impulse noises may not register at all, but will certainly be noticed by a human
       well we'll deal with that later, I can already think of a processing scheme to incorporate this.
 */
 

/*--------------------------------
 *   Memory sizes, constants, macros, and related items
 *--------------------------------*/
#define SAMPLE_RATE_IN_HZ (EXPECTED_AUDIO_SAMPLE_RATE_HZ / AUDIO_FFT_SIZE)
#define SAMPLE_PERIOD_IN_MILLISECONDS  (1000 / SAMPLE_RATE_IN_HZ)

#define FEAT_BUF_SIZE_2N (4)
#define FEAT_BUF_SIZE (1 << FEAT_BUF_SIZE_2N)
#define FEAT_BUF_MASK (FEAT_BUF_SIZE - 1)

#define ENERGY_BUF_SIZE_2N (4)
#define ENERGY_BUF_SIZE (1 << ENERGY_BUF_SIZE_2N)
#define ENERGY_BUF_MASK (ENERGY_BUF_SIZE - 1)

#define ENERGYDIFF_BUF_SIZE_2N (1)
#define ENERGYDIFF_BUF_SIZE  (1 << ENERGYDIFF_BUF_SIZE_2N)
#define ENERGYDIFF_BUF_MASK (ENERGYDIFF_BUF_SIZE - 1)

#define CHANGE_SIGNAL_BUF_SIZE_2N (5)
#define CHANGE_SIGNAL_BUF_SIZE (1 << CHANGE_SIGNAL_BUF_SIZE_2N)
#define CHANGE_SIGNAL_BUF_MASK (CHANGE_SIGNAL_BUF_SIZE - 1)

#define STEADY_STATE_AVERAGING_PERIOD_2N (6)
#define STEADY_STATE_AVERAGING_PERIOD (1 << STEADY_STATE_AVERAGING_PERIOD_2N)

#define STARTUP_PERIOD_IN_MS (10000)
#define STARTUP_EQUALIZATION_COUNTS (STARTUP_PERIOD_IN_MS / SAMPLE_PERIOD_IN_MILLISECONDS)

#define NUM_AUDIO_SHAPE_FEATURES (16)

#define MUL(a,b,q)\
  ((int16_t)((((int32_t)(a)) * ((int32_t)(b))) >> q))

#define MUL_PRECISE_RESULT(a,b,q)\
((int32_t)((((int32_t)(a)) * ((int32_t)(b))) >> q))

#define TOFIX(x,q)\
  ((int32_t) ((x) * (float)(1 << (q))))

#define QFIXEDPOINT (12)
#define TRUE (1)
#define FALSE (0)

#define MAX_INT_16 (32767)

//purposely DO NOT MAKE THIS -32768
// abs(-32768) is 32768.  I can't represent this number with an int16 type!
#define MIN_INT_16 (-32767)
#define MIN_INT_32 (-2147483647)

/* Have fun tuning these magic numbers!
 Perhaps eventually we will have some pre-canned
 data to show you how?  */

//the higher this gets, the less likely you are to be stable
static const int16_t k_stable_likelihood_coefficient = TOFIX(1.0,QFIXEDPOINT);

//the closer this gets to zero, the more likely it is that you will be increasing or decreasing
static const int16_t k_change_log_likelihood = TOFIX(-0.10f,QFIXEDPOINT);

//the closer this gets to zero, the shorter the amount of time it will take to switch between modes
//the more negative it gets, the more evidence is required before switching modes, in general
static const int32_t k_min_log_prob = TOFIX(-0.25f,QFIXEDPOINT);

static const int16_t k_coherence_slope = TOFIX(1.0f,QFIXEDPOINT);
static const int16_t k_incoherence_slope = TOFIX(1.0f,QFIXEDPOINT);
static const int32_t k_coherence_min_log_prob = TOFIX(-0.25f,QFIXEDPOINT);

#define STABLE_TIME_TO_BE_CONSIDERED_STABLE_IN_MILLISECONDS  (500)

static const uint32_t k_stable_counts_to_be_considered_stable =  STABLE_TIME_TO_BE_CONSIDERED_STABLE_IN_MILLISECONDS / SAMPLE_PERIOD_IN_MILLISECONDS;


static const int32_t k_min_energy = 3000;

/*--------------------------------
 *   Types
 *--------------------------------*/
typedef enum {
    stable,
    increasing,
    decreasing,
    numChangeModes
} EChangeModes_t;

typedef enum {
    incoherent,
    coherent,
    numCoherencyModes
} ECoherencyModes_t;

typedef struct {
    //needed for equalization of spectrum
    int16_t lpfbuf[AUDIO_FFT_SIZE / 4]; //256 * 2 = 0.5K
    
    int16_t featbuf[NUM_AUDIO_SHAPE_FEATURES][FEAT_BUF_SIZE]; //8 * 128 * 2 = 2K
    int32_t featbufaccumulator[NUM_AUDIO_SHAPE_FEATURES];
    
    int16_t energybuf[ENERGY_BUF_SIZE];
    int32_t energyaccumulator;
    
    int16_t energydiffbuf[ENERGYDIFF_BUF_SIZE];
    int32_t energydiffaccumulator;
    
    int16_t lastmfcc[NUM_AUDIO_SHAPE_FEATURES];
    
    int16_t lastEnergy;
    
    uint16_t callcounter;
    uint16_t steadyStateCounter;
    
    int16_t changebuf[CHANGE_SIGNAL_BUF_SIZE];
    int32_t logProbOfModes[numChangeModes];
    int32_t logProbOfCoherencyModes[numCoherencyModes];
    uint8_t isStable;
    int16_t energyStable;
    uint32_t stableCount;
    uint32_t stablePeriodCounter;
    EChangeModes_t lastModes[3];
    int64_t modechangeTimes[3];
    uint8_t isValidSteadyStateSegment;
    int16_t maxenergyfeatures[NUM_AUDIO_FEATURES];
    int16_t maxenergyinsegment;
    

    SegmentAndFeatureCallback_t fpCallback;
    
} MelFeatures_t;


typedef enum {
    eAudioSignalIsNotInteresting,
    eAudioSignalIsDiverse,
    eAudioSignalIsSimilar
} EAudioSignalSimilarity_t;

/*--------------------------------
 *   Static Memory Declarations
 *--------------------------------*/
static MelFeatures_t _data;




/*--------------------------------
 *   Functions
 *--------------------------------*/
void AudioFeatures_Init(SegmentAndFeatureCallback_t fpCallback) {
    
    memset(&_data,0,sizeof(_data));
    
    _data.fpCallback = fpCallback;
    
    _data.maxenergyinsegment = MIN_INT_16;
}

static int16_t MovingAverage16(uint32_t counter, const int16_t x,int16_t * buf, int32_t * accumulator,const uint32_t mask,const uint8_t shiftnum) {
    const uint16_t idx = counter & mask;
    
    /* accumulate */
    uint32_t a = *accumulator;
    /* add new measurement to accumulator */
    a += x;
    
    /*  remove oldest measurement from accumulator */
    a -= buf[idx];
    
    /*  store new measurement */
    buf[idx] = x;
    
    *accumulator = a;
    
    return (int16_t) (a >> shiftnum);
}


static uint8_t IsStable(EChangeModes_t currentMode,const int16_t energySignal) {
    
    uint8_t isStable = FALSE;
    
 
    if (currentMode != stable) {
        _data.stableCount = 0;
    }
    else {
        
        //increment stable count
        if ((++_data.stableCount) == 0) {
            _data.stableCount = 0xFFFFFFFF;
        };
        
    }
    
    //segment steady state (i.e. energy has been the same)
    if (_data.stableCount > k_stable_counts_to_be_considered_stable) {
        isStable = TRUE;
    }

    return isStable;
    
}


static void UpdateChangeSignals(EChangeModes_t * pCurrentMode, const int16_t newestenergy, uint32_t counter) {
    const uint16_t idx = counter & CHANGE_SIGNAL_BUF_MASK;
    const int32_t oldestenergy = _data.changebuf[idx];
    int32_t change32;
    int16_t change16;
    int32_t logLikelihoodOfModePdfs[numChangeModes];
    int32_t * logProbOfModes = _data.logProbOfModes;
    int16_t i;
    int16_t maxidx;
    int32_t maxlogprob;
    
   
    
    /* update buffer */
    _data.changebuf[idx] = newestenergy;

    change32 = (int32_t)newestenergy - (int32_t)oldestenergy;
    
    if (change32 < MIN_INT_16) {
        change32 = MIN_INT_16;
    }
    
    if (change32 > MAX_INT_16) {
        change32 = MAX_INT_16;
    }
    
    change16 = change32;
    //DEBUG_LOG_S16("change", NULL, &change16, 1, counter, counter);
    
    //evaluate log likelihood and compute Bayes update
    /*
     
     
     This is my likelihood function
     exp(-|x|/a)   I could do exp(-x^2 / b) or something, but I don't want to deal with the x^2 in fixed point
      
     Hypothesis 1 - No change
     
               p(x)
            /|\
           / | \
          /  |  \
         /   |   \
    <--------0----------->  change signal (x)
     
     
     Hypothesis 2 - change  
     
     uniform likelihood function
     
             |
             |
             |   p(x)
    <--------|--------------->
    <--------0----------->   change signal

     
     */
    
    if (change16 > 0) {
        logLikelihoodOfModePdfs[increasing] = k_change_log_likelihood;
        logLikelihoodOfModePdfs[decreasing] = MIN_INT_16;
    }
    else if (change16 < 0) {
        logLikelihoodOfModePdfs[increasing] = MIN_INT_16;
        logLikelihoodOfModePdfs[decreasing] = k_change_log_likelihood;

    }
    else {
        logLikelihoodOfModePdfs[increasing] = k_change_log_likelihood;
        logLikelihoodOfModePdfs[decreasing] = k_change_log_likelihood;
    }
    
    change16 = -abs(change16);
    logLikelihoodOfModePdfs[stable] = MUL_PRECISE_RESULT(change16,k_stable_likelihood_coefficient,QFIXEDPOINT);
    //DEBUG_LOG_S32("loglik", NULL, logLikelihoodOfModePdfs, 3, counter, counter);
    
    
    /* Bayes rule 
     
                    P(B|Ai) P(Ai)
       P(Ai|B) =   ------------------
                   sum_j(P(B|Aj) P(Aj))
     
     
       or for a continuous measurements
     
                    P(y | Ai) P(Ai)
       P(Ai|y) =  -----------------
                   sum_j[P(x|Aj) P(Aj)]
     
     
     
        Of course the denominator is just there to make sure that sum(P) = 1, so let's just ignore that
        for now and take the log of everything
     
        log P(Ai | y) = log P(y | Ai) + log P(Ai)
     
      So for our two hypotheses:
     
         log P(change | y ) = log P(y | change) + log P(change)
        
         log P(no change | y) = log P(y | no change) + log P(no change)
     
      *** updating log likelihood is now just an addition ***
     
      Which hypothesis is more likely?  loglik1 > loglik2? hypothesis 1 is more likely
      Since we're just tracking the differnece between logP1 and logP2, if this difference
      (let's call it "z") exceeds 0, then P2 is more likely than P1
     
     */
    
   
    for (i = 0; i < numChangeModes; i++) {
        logProbOfModes[i] += logLikelihoodOfModePdfs[i];
    }
    
    
    /* normalize -- the highest log probability will now be 0 */
    maxlogprob = logProbOfModes[0];
    maxidx = 0;
    for (i = 1; i < numChangeModes; i++) {
        if (logProbOfModes[i] > maxlogprob) {
            maxlogprob = logProbOfModes[i];
            maxidx = i;
        }
    }
    
    for (i = 0; i < numChangeModes; i++) {
        logProbOfModes[i] -= maxlogprob;
    }
    
    /* enforce min log prob */
    for (i = 0; i < numChangeModes; i++) {
        if (logProbOfModes[i] < k_min_log_prob) {
            logProbOfModes[i] = k_min_log_prob;
        }
    }
    
    *pCurrentMode = (EChangeModes_t)maxidx;
    
#if 0
    switch (*pCurrentMode) {
        case stable:
            printf("stable\n");
            break;
            
        case increasing:
            printf("increasing\n");

            
            break;
            
        case decreasing:
            
            printf("decreasing\n");

            break;
            
            default:
            break;
    }
    
#endif
    
}

static void UpdateCoherencySignals(ECoherencyModes_t * pCurrentMode, const int16_t cosangle, uint32_t counter) {

    int32_t logLikelihoodOfModePdfs[numCoherencyModes];
    int32_t * logProbOfModes = _data.logProbOfCoherencyModes;
    int16_t i;
    int16_t coherentSignal = -((1<<10) - cosangle);
    int16_t incoherentSignal = -(cosangle);
    int32_t maxlogprob;
    int16_t maxidx;
    
    
    
 /*  Mode log pdfs
(0,0)|B\    /| (1,0)
     |  \  /A|
     |   \/  |
     |  / \  |
     | /   \ |
     |/     \|
     .       .
     .       .
  (0,-m)  (1,-n)
     
     pdf A is coherency (as cos angle goes to 1, your signal is more coherent)
  
     */
    

    
    logLikelihoodOfModePdfs[coherent] = MUL_PRECISE_RESULT(coherentSignal,k_coherence_slope,QFIXEDPOINT);
    logLikelihoodOfModePdfs[incoherent] = MUL_PRECISE_RESULT(incoherentSignal,k_incoherence_slope,QFIXEDPOINT);
    
    DEBUG_LOG_S32("loglik", NULL, logLikelihoodOfModePdfs, numCoherencyModes, counter, counter);

    for (i = 0; i < numCoherencyModes; i++) {
        logProbOfModes[i] += logLikelihoodOfModePdfs[i];
    }
    
    
    /* normalize -- the highest log probability will now be 0 */
    maxlogprob = logProbOfModes[0];
    maxidx = 0;
    for (i = 1; i < numCoherencyModes; i++) {
        if (logProbOfModes[i] > maxlogprob) {
            maxlogprob = logProbOfModes[i];
            maxidx = i;
        }
    }
    
    for (i = 0; i < numCoherencyModes; i++) {
        logProbOfModes[i] -= maxlogprob;
    }
    
    /* enforce min log prob */
    for (i = 0; i < numCoherencyModes; i++) {
        if (logProbOfModes[i] < k_coherence_min_log_prob) {
            logProbOfModes[i] = k_coherence_min_log_prob;
        }
    }
    
    *pCurrentMode = (ECoherencyModes_t)maxidx;
    
#if 0
    switch (*pCurrentMode) {
        case coherent:
            printf("coherent\n");
            break;
            
        case incoherent:
            printf("incoherent\n");
            
            
            break;
            
        default:
            break;
    }
    
#endif
    
}


static void ScaleInt16Vector(int16_t * vec, uint8_t * scaling, uint16_t len,uint8_t desiredscaling) {
    uint16_t utemp16;
    uint16_t max;
    uint16_t i;
    uint8_t log2scale;
    
    /* Normalize signal  */
    max = 0;
    
    for (i = 0; i < len; i++) {
        utemp16 = abs(vec[i]);
        
        if (utemp16 > max) {
            max = utemp16;
        }
    }
    
    log2scale = desiredscaling - CountHighestMsb(max);
    
    if (log2scale > 0) {
        for (i = 0; i < len; i++) {
            vec[i] = vec[i] << log2scale;
        }
    }
    else {
        log2scale = 0;
    }
    
    *scaling = log2scale;
    
}


static int16_t cosvec(const int16_t * vec1, const int16_t * vec2, uint8_t n) {
    int32_t temp1,temp2,temp3;
    static const uint8_t q = 10;
    uint8_t i;
    
    temp1 = 0;
    temp2 = 0;
    temp3 = 0;
    for (i = 0; i < n; i++) {
        temp1 += (int32_t)vec1[i]*(int32_t)vec1[i];
        temp2 += (int32_t)vec2[i]*(int32_t)vec2[i];
        temp3 += (int32_t)vec1[i]*(int32_t)vec2[i];
    }
    
    if (!temp1 || !temp2) {
        return INT16_MAX;
    }
    
    temp1 = fxd_sqrt(temp1);
    temp2 = fxd_sqrt(temp2);
    
    if (temp1 > temp2) {
        temp3 /= temp2;
        temp3 <<= q;
        temp3 /= temp1;
    }
    else {
        temp3 /= temp1;
        temp3 <<= q;
        temp3 /= temp2;
    }
    
    return (int16_t) temp3;
    
}


/*
 *  Given AUDIO_FFT_SIZE of samples, it will return the time averaged MFCC coefficients.
 *
 *    nfftsize = log2(AUDIO_FFT_SIZE)  ergo if AUDIO_FFT_SIZE == 1024, nfftsize == 10
 * 
 *  TODO: Put in delta MFCC features, and maybe average those too.
 *
 */
#define RAW_SAMPLES_SCALE (14)

void AudioFeatures_SetAudioData(const int16_t samples[],int16_t nfftsize,int64_t samplecount) {
    //enjoy this nice large stack.
    //this can all go away if we get fftr to work, and do the
    int16_t fr[AUDIO_FFT_SIZE]; //2K
    int16_t fi[AUDIO_FFT_SIZE]; //2K
  
    uint16_t i,j;
    uint8_t log2scaleOfRawSignal;
    int16_t mfcc[NUM_AUDIO_SHAPE_FEATURES];
    int16_t logTotalEnergy;
    EChangeModes_t currentMode;
    ECoherencyModes_t coherencyMode;
    uint8_t isStable;
    int16_t * psd = &fr[AUDIO_FFT_SIZE/2];
    uint8_t isSegmentReady;
    Segment_t seg;
    int16_t feats[NUM_AUDIO_FEATURES];
    int16_t vecdotresult;
    
    

    
    /* Copy in raw samples, zero out complex part of fft input*/
    memcpy(fr,samples,AUDIO_FFT_SIZE*sizeof(int16_t));
    memset(fi,0,sizeof(fi));
    
    
    
    /* Normalize time series signal  */
    ScaleInt16Vector(fr,&log2scaleOfRawSignal,AUDIO_FFT_SIZE,RAW_SAMPLES_SCALE);

    
    
    
    /* Get FFT */
    fft(fr,fi, AUDIO_FFT_SIZE_2N);
    
    /* Get PSD, but we only care about the PSD up until ~10 Khz, so we will stop at 256 */
    logpsd(&logTotalEnergy,psd,fr, fi, log2scaleOfRawSignal, AUDIO_FFT_SIZE/4);
    
    
    /* Determine stability in order to figure out when to subtract out background spectrum */
    
    logTotalEnergy = MovingAverage16(_data.callcounter, logTotalEnergy, _data.energybuf, &_data.energyaccumulator,ENERGY_BUF_MASK,ENERGY_BUF_SIZE_2N);
    

    UpdateChangeSignals(&currentMode, logTotalEnergy, _data.callcounter);

    isStable = IsStable(currentMode,logTotalEnergy);
    

    /* Equalize the PSD */
    
    //only do adaptive equalization if we are starting up, or our energy level is stable
    if (isStable || logTotalEnergy < k_min_energy ||  _data.callcounter < STARTUP_EQUALIZATION_COUNTS) {
        
        //crappy adaptive equalization. lowpass the psd, and subtract that from the psd
        for (i = 0; i < AUDIO_FFT_SIZE/4; i++) {
            _data.lpfbuf[i] = MUL(_data.lpfbuf[i], TOFIX(0.99f,15), 15) + MUL(psd[i], TOFIX(0.01f,15), 15);
        }
       
    }
    
    //get MFCC coefficients
    memset(fi,0,sizeof(fi));

    for (i = 0; i < AUDIO_FFT_SIZE/4; i++) {
        fr[i] = psd[i] - _data.lpfbuf[i];
    }
    
    
    //fft of 2^8 --> 256
    dct(fr,fi,AUDIO_FFT_SIZE_2N - 2);
    
    //here they are
    for (j = 0; j < NUM_AUDIO_SHAPE_FEATURES; j++) {
        mfcc[j] = fr[j+1];
    }
    
    //now compute MFCC directional change
    vecdotresult = cosvec(_data.lastmfcc,mfcc,NUM_AUDIO_SHAPE_FEATURES);
    memcpy(_data.lastmfcc,mfcc,sizeof(_data.lastmfcc));

    //vecdotresult = MovingAverage16(_data.callcounter, vecdotresult, _data.energydiffbuf, &_data.energydiffaccumulator,ENERGYDIFF_BUF_MASK,ENERGYDIFF_BUF_SIZE_2N);
    DEBUG_LOG_S16("cosvec",NULL,&vecdotresult,1,samplecount,samplecount);
    
    UpdateCoherencySignals(&coherencyMode,vecdotresult,_data.callcounter);

    SetDebugVectorS16("coherent", NULL, (int16_t *)&coherencyMode, 1, samplecount, samplecount);
    
    memcpy(&feats[0],mfcc,NUM_AUDIO_SHAPE_FEATURES*sizeof(int16_t));

    /*
    if (((_data.callcounter + 1) & FEAT_BUF_MASK) == 0) {
        DEBUG_LOG_S16("sampledfeats",NULL,feats,NUM_AUDIO_FEATURES,samplecount,samplecount);
        DEBUG_LOG_S16("sampledshapes",NULL,mfcc,NUM_AUDIO_SHAPE_FEATURES,samplecount,samplecount);

    }
     */
   
    if (!isStable) {
        DEBUG_LOG_S16("shapes",NULL,mfcc,NUM_AUDIO_SHAPE_FEATURES,samplecount,samplecount);
    }
    


    
    for (i = 0; i < NUM_AUDIO_SHAPE_FEATURES; i++) {
        mfcc[i] >>= 4;
    }
    
   
    DEBUG_LOG_S16("shapes2",NULL,mfcc,NUM_AUDIO_SHAPE_FEATURES,samplecount,samplecount);


    


    

    
    if (currentMode == increasing) {
        _data.maxenergyinsegment = MIN_INT_16;
    }
    
    if (_data.maxenergyinsegment < logTotalEnergy) {
        _data.maxenergyinsegment = logTotalEnergy;
        memcpy(_data.maxenergyfeatures,feats,sizeof(_data.maxenergyfeatures));
    }
    
   /*
    if (isSegmentReady && _data.callcounter > STARTUP_EQUALIZATION_COUNTS) {
        if (seg.type == segmentPacket) {
            _data.fpCallback(_data.maxenergyfeatures,&seg);
        }
        else if (seg.type == segmentSteadyState) {
            _data.fpCallback(feats,&seg);

        }
    }
    */
    
    
    /* Update counter.  It's okay if this one rolls over*/
    _data.callcounter++;
    
    
}
