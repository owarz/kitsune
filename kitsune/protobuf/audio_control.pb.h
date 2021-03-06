/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.1 at Tue Dec 23 11:10:21 2014. */

#ifndef PB_AUDIO_CONTROL_PB_H_INCLUDED
#define PB_AUDIO_CONTROL_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _AudioClassifierMessage_ClassifierType {
    AudioClassifierMessage_ClassifierType_LINEARSVM = 0
} AudioClassifierMessage_ClassifierType;

typedef enum _AudioControl_AudioCaptureAction {
    AudioControl_AudioCaptureAction_OFF = 0,
    AudioControl_AudioCaptureAction_ON = 1
} AudioControl_AudioCaptureAction;

/* Struct definitions */
typedef struct _AudioClassifierMessage {
    pb_size_t idata_count;
    int32_t idata[85];
    bool has_numclasses;
    int32_t numclasses;
    bool has_type;
    AudioClassifierMessage_ClassifierType type;
} AudioClassifierMessage;

typedef struct _AudioControl {
    bool has_audio_min_energy_threshold;
    int32_t audio_min_energy_threshold;
    bool has_audio_num_feat_vecs_until_attempt_feature_upload;
    int32_t audio_num_feat_vecs_until_attempt_feature_upload;
    bool has_audio_feat_buffer_size;
    int32_t audio_feat_buffer_size;
    bool has_audio_recording_period_in_frames;
    int32_t audio_recording_period_in_frames;
    bool has_audio_capture_action;
    AudioControl_AudioCaptureAction audio_capture_action;
    bool has_audio_capture_classifier;
    AudioClassifierMessage audio_capture_classifier;
    bool has_audio_capture_hmm;
    AudioClassifierMessage audio_capture_hmm;
    bool has_audio_save_raw_data;
    AudioControl_AudioCaptureAction audio_save_raw_data;
    bool has_audio_save_features;
    AudioControl_AudioCaptureAction audio_save_features;
} AudioControl;

/* Default values for struct fields */

/* Initializer values for message structs */
#define AudioClassifierMessage_init_default      {0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false, 0, false, (AudioClassifierMessage_ClassifierType)0}
#define AudioControl_init_default                {false, 0, false, 0, false, 0, false, 0, false, (AudioControl_AudioCaptureAction)0, false, AudioClassifierMessage_init_default, false, AudioClassifierMessage_init_default, false, (AudioControl_AudioCaptureAction)0, false, (AudioControl_AudioCaptureAction)0}
#define AudioClassifierMessage_init_zero         {0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false, 0, false, (AudioClassifierMessage_ClassifierType)0}
#define AudioControl_init_zero                   {false, 0, false, 0, false, 0, false, 0, false, (AudioControl_AudioCaptureAction)0, false, AudioClassifierMessage_init_zero, false, AudioClassifierMessage_init_zero, false, (AudioControl_AudioCaptureAction)0, false, (AudioControl_AudioCaptureAction)0}

/* Field tags (for use in manual encoding/decoding) */
#define AudioClassifierMessage_idata_tag         1
#define AudioClassifierMessage_numclasses_tag    2
#define AudioClassifierMessage_type_tag          3
#define AudioControl_audio_min_energy_threshold_tag 1
#define AudioControl_audio_num_feat_vecs_until_attempt_feature_upload_tag 2
#define AudioControl_audio_feat_buffer_size_tag  3
#define AudioControl_audio_recording_period_in_frames_tag 4
#define AudioControl_audio_capture_action_tag    8
#define AudioControl_audio_capture_classifier_tag 9
#define AudioControl_audio_capture_hmm_tag       10
#define AudioControl_audio_save_raw_data_tag     11
#define AudioControl_audio_save_features_tag     12

/* Struct field encoding specification for nanopb */
extern const pb_field_t AudioClassifierMessage_fields[4];
extern const pb_field_t AudioControl_fields[10];

/* Maximum encoded size of messages (where known) */
#define AudioClassifierMessage_size              527
#define AudioControl_size                        1122

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
