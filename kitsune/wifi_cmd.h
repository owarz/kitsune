#ifndef __WIFI_CMD_H__
#define __WIFI_CMD_H__

#include "periodic.pb.h"
#define DATA_SERVER                         "dev-in.hello.is"
#define DATA_RECEIVE_ENDPOINT               "/in/morpheus/pb2"
#define MORPHEUS_REGISTER_ENDPOINT          "/register/morpheus"
#define PILL_REGISTER_ENDPOINT              "/register/pill"

#define PILL_ID_LEN 16
typedef struct {
	uint32_t magic;
	char id[PILL_ID_LEN+1];
	periodic_data_pill_data pill_data;
} periodic_data_pill_data_container;
#define PILL_MAGIC 0xAAAAAAAA
#define MAX_PILLS 8
#include "FreeRTOS.h"
#include "semphr.h"
#include "wlan.h"
#include "ble_cmd.h"

extern xSemaphoreHandle pill_smphr;

typedef struct {
	unsigned int time;
	int light, light_variability, light_tonality, temp, humid, dust, dust_max, dust_min, dust_var;
	periodic_data_pill_data_container * pill_list;
} data_t;

extern
int sl_mode;

extern periodic_data_pill_data_container pill_list[MAX_PILLS];

#define CONNECT    0x00000001
#define HAS_IP     0x00000002
#define IP_LEASED  0x00000004
#define SCANNING   0x00000008
#define CONNECTING 0x00000010
#define UPLOADING  0x00000020

#define AES_KEY_LOC "/cert/key.aes"

#include "stdint.h"
#include "SyncResponse.pb.h"

#define INV_TIME 0xffffffff
extern
SyncResponse_Alarm alarm;

extern
unsigned int sl_status;

#define IFA_ANT 1
#define CHIP_ANT 2
void antsel(unsigned char a);
int Cmd_antsel(int argc, char *argv[]);

int Cmd_connect(int argc, char *argv[]);
int Cmd_disconnect(int argc, char *argv[]);
int Cmd_ping(int argc, char *argv[]);
int Cmd_status(int argc, char *argv[]);
int Cmd_audio_test(int argc, char *argv[]);
int Cmd_time(int argc, char*argv[]);
int Cmd_sl(int argc, char*argv[]);
int Cmd_mode(int argc, char*argv[]);
int Cmd_set_mac(int argc, char*argv[]);
int Cmd_set_aes(int argc, char *argv[]) ;

int Cmd_RadioStartRX(int argc, char*argv[]);
int Cmd_RadioStopRX(int argc, char*argv[]);
int Cmd_RadioStopTX(int argc, char*argv[]);
int Cmd_RadioStartTX(int argc, char*argv[]);
int Cmd_RadioGetStats(int argc, char*argv[]);
int Cmd_data_upload(int arg, char* argv[]);

int match(char *regexp, char *text);
unsigned long unix_time();
void load_aes();

int send_periodic_data(array_data* data );
int send_audio_data( data_t * data );

void thread_ota( void * unused );

int send_data_pb(const char* host, const char* path, 
	const uint8_t* buffer_in, size_t content_len,
    char * buffer_out, int buffer_size, 
    const pb_field_t fields[], const void *src_struct);
int decode_rx_data_pb(const unsigned char * buffer, int buffer_size, 
    const pb_field_t fields[], void* dst_struct, size_t dst_struct_len);
int http_response_ok(const char* response_buffer);

int get_wifi_scan_result(Sl_WlanNetworkEntry_t* entries, uint16_t entry_len, uint32_t scan_duration_ms);
int connect_scanned_endpoints(const char* ssid, const char* password, 
    const Sl_WlanNetworkEntry_t* wifi_endpoints, int scanned_wifi_count, SlSecParams_t* connectedEPSecParamsPtr);

void wifi_reset();

bool encode_mac(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);
bool encode_mac_as_device_id_string(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);
bool encode_name(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

bool encode_pill_list(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);
void encode_pill_list_to_buffer(const periodic_data_pill_data_container* ptr_pill_list, 
    uint8_t* buffer, size_t buffer_len, size_t* out_len);
bool encode_serialized_pill_list(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

//#define MORPH_NAME "KingShy's morpheus"

//#define MORPH_NAME "Chris's morpheus"
#define MORPH_NAME "test morpheus 10"
//#define MORPH_NAME "test morpheus 80"
#define KIT_VER 10

#endif
