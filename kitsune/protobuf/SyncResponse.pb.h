/* Automatically generated nanopb header */
/* Generated by nanopb-0.2.9-dev at Tue Sep 02 14:15:39 2014. */

#ifndef _PB_SYNCRESPONSE_PB_H_
#define _PB_SYNCRESPONSE_PB_H_
#include <pb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _SyncResponse_PairingAction_ActionType {
    SyncResponse_PairingAction_ActionType_PAIR = 0,
    SyncResponse_PairingAction_ActionType_UNPAIR = 1
} SyncResponse_PairingAction_ActionType;

/* Struct definitions */
typedef struct _SyncResponse_Alarm {
    bool has_start_time;
    int32_t start_time;
    bool has_end_time;
    int32_t end_time;
    bool has_ringtone_id;
    int32_t ringtone_id;
} SyncResponse_Alarm;

typedef struct _SyncResponse_FlashAction_LEDAction {
    bool has_color;
    int32_t color;
    bool has_start_time;
    int32_t start_time;
    bool has_end_time;
    int32_t end_time;
} SyncResponse_FlashAction_LEDAction;

typedef struct _SyncResponse_PairingAction {
    pb_callback_t ssid;
    bool has_type;
    SyncResponse_PairingAction_ActionType type;
} SyncResponse_PairingAction;

typedef struct _SyncResponse_WhiteNoise {
    bool has_start_time;
    int32_t start_time;
    bool has_end_time;
    int32_t end_time;
    bool has_sound_id;
    int32_t sound_id;
} SyncResponse_WhiteNoise;

typedef struct _SyncResponse_FlashAction {
    bool has_led_1;
    SyncResponse_FlashAction_LEDAction led_1;
    bool has_led_2;
    SyncResponse_FlashAction_LEDAction led_2;
    bool has_led_3;
    SyncResponse_FlashAction_LEDAction led_3;
    bool has_led_4;
    SyncResponse_FlashAction_LEDAction led_4;
    bool has_led_5;
    SyncResponse_FlashAction_LEDAction led_5;
} SyncResponse_FlashAction;

typedef struct _SyncResponse {
    bool has_upload_cycle;
    int32_t upload_cycle;
    bool has_sync_cycle;
    int32_t sync_cycle;
    bool has_acc_scan_cyle;
    int32_t acc_scan_cyle;
    bool has_acc_sampling_interval;
    int32_t acc_sampling_interval;
    bool has_device_sampling_interval;
    int32_t device_sampling_interval;
    bool has_alarm;
    SyncResponse_Alarm alarm;
    bool has_pairing_action;
    SyncResponse_PairingAction pairing_action;
    bool has_white_noise;
    SyncResponse_WhiteNoise white_noise;
    bool has_flash_action;
    SyncResponse_FlashAction flash_action;
} SyncResponse;

/* Default values for struct fields */
extern const int32_t SyncResponse_Alarm_ringtone_id_default;

/* Field tags (for use in manual encoding/decoding) */
#define SyncResponse_Alarm_start_time_tag        1
#define SyncResponse_Alarm_end_time_tag          2
#define SyncResponse_Alarm_ringtone_id_tag       3
#define SyncResponse_FlashAction_LEDAction_color_tag 1
#define SyncResponse_FlashAction_LEDAction_start_time_tag 2
#define SyncResponse_FlashAction_LEDAction_end_time_tag 3
#define SyncResponse_PairingAction_ssid_tag      1
#define SyncResponse_PairingAction_type_tag      2
#define SyncResponse_WhiteNoise_start_time_tag   1
#define SyncResponse_WhiteNoise_end_time_tag     2
#define SyncResponse_WhiteNoise_sound_id_tag     3
#define SyncResponse_FlashAction_led_1_tag       1
#define SyncResponse_FlashAction_led_2_tag       2
#define SyncResponse_FlashAction_led_3_tag       3
#define SyncResponse_FlashAction_led_4_tag       4
#define SyncResponse_FlashAction_led_5_tag       5
#define SyncResponse_upload_cycle_tag            1
#define SyncResponse_sync_cycle_tag              2
#define SyncResponse_acc_scan_cyle_tag           3
#define SyncResponse_acc_sampling_interval_tag   4
#define SyncResponse_device_sampling_interval_tag 5
#define SyncResponse_alarm_tag                   6
#define SyncResponse_pairing_action_tag          7
#define SyncResponse_white_noise_tag             8
#define SyncResponse_flash_action_tag            9

/* Struct field encoding specification for nanopb */
extern const pb_field_t SyncResponse_fields[10];
extern const pb_field_t SyncResponse_Alarm_fields[4];
extern const pb_field_t SyncResponse_PairingAction_fields[3];
extern const pb_field_t SyncResponse_WhiteNoise_fields[4];
extern const pb_field_t SyncResponse_FlashAction_fields[6];
extern const pb_field_t SyncResponse_FlashAction_LEDAction_fields[4];

/* Maximum encoded size of messages (where known) */
#define SyncResponse_Alarm_size                  33
#define SyncResponse_WhiteNoise_size             33
#define SyncResponse_FlashAction_size            175
#define SyncResponse_FlashAction_LEDAction_size  33

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
