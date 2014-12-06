/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.1 at Sat Dec  6 09:51:32 2014. */

#include "sync_response.pb.h"

#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

const int32_t SyncResponse_Alarm_ringtone_id_default = 1;


const pb_field_t SyncResponse_fields[19] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, SyncResponse, upload_cycle, upload_cycle, 0),
    PB_FIELD(  2, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse, sync_cycle, upload_cycle, 0),
    PB_FIELD(  3, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse, acc_scan_cyle, sync_cycle, 0),
    PB_FIELD(  4, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse, acc_sampling_interval, acc_scan_cyle, 0),
    PB_FIELD(  5, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse, device_sampling_interval, acc_sampling_interval, 0),
    PB_FIELD(  6, MESSAGE , OPTIONAL, STATIC  , OTHER, SyncResponse, alarm, device_sampling_interval, &SyncResponse_Alarm_fields),
    PB_FIELD(  7, MESSAGE , OPTIONAL, STATIC  , OTHER, SyncResponse, pairing_action, alarm, &SyncResponse_PairingAction_fields),
    PB_FIELD(  8, MESSAGE , OPTIONAL, STATIC  , OTHER, SyncResponse, white_noise, pairing_action, &SyncResponse_WhiteNoise_fields),
    PB_FIELD(  9, MESSAGE , OPTIONAL, STATIC  , OTHER, SyncResponse, flash_action, white_noise, &SyncResponse_FlashAction_fields),
    PB_FIELD( 10, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse, reset_device, flash_action, 0),
    PB_FIELD( 12, ENUM    , OPTIONAL, STATIC  , OTHER, SyncResponse, room_conditions, reset_device, 0),
    PB_FIELD( 13, MESSAGE , REPEATED, CALLBACK, OTHER, SyncResponse, files, room_conditions, &SyncResponse_FileDownload_fields),
    PB_FIELD( 14, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse, reset_to_factory_fw, files, 0),
    PB_FIELD( 15, MESSAGE , OPTIONAL, STATIC  , OTHER, SyncResponse, audio_control, reset_to_factory_fw, &AudioControl_fields),
    PB_FIELD( 16, UINT32  , OPTIONAL, STATIC  , OTHER, SyncResponse, unix_time, audio_control, 0),
    PB_FIELD( 17, MESSAGE , OPTIONAL, STATIC  , OTHER, SyncResponse, led_action, unix_time, &SyncResponse_LEDAction_fields),
    PB_FIELD( 18, BYTES   , OPTIONAL, STATIC  , OTHER, SyncResponse, mac, led_action, 0),
    PB_FIELD( 19, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse, batch_size, mac, 0),
    PB_LAST_FIELD
};

const pb_field_t SyncResponse_FileDownload_fields[11] = {
    PB_FIELD(  1, STRING  , OPTIONAL, CALLBACK, FIRST, SyncResponse_FileDownload, host, host, 0),
    PB_FIELD(  2, STRING  , OPTIONAL, CALLBACK, OTHER, SyncResponse_FileDownload, url, host, 0),
    PB_FIELD(  3, STRING  , OPTIONAL, CALLBACK, OTHER, SyncResponse_FileDownload, sd_card_filename, url, 0),
    PB_FIELD(  4, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse_FileDownload, copy_to_serial_flash, sd_card_filename, 0),
    PB_FIELD(  5, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse_FileDownload, reset_network_processor, copy_to_serial_flash, 0),
    PB_FIELD(  6, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse_FileDownload, reset_application_processor, reset_network_processor, 0),
    PB_FIELD(  7, STRING  , OPTIONAL, CALLBACK, OTHER, SyncResponse_FileDownload, serial_flash_filename, reset_application_processor, 0),
    PB_FIELD(  8, STRING  , OPTIONAL, CALLBACK, OTHER, SyncResponse_FileDownload, serial_flash_path, serial_flash_filename, 0),
    PB_FIELD(  9, STRING  , OPTIONAL, CALLBACK, OTHER, SyncResponse_FileDownload, sd_card_path, serial_flash_path, 0),
    PB_FIELD( 10, BYTES   , OPTIONAL, STATIC  , OTHER, SyncResponse_FileDownload, sha1, sd_card_path, 0),
    PB_LAST_FIELD
};

const pb_field_t SyncResponse_Alarm_fields[6] = {
    PB_FIELD(  1, UINT32  , OPTIONAL, STATIC  , FIRST, SyncResponse_Alarm, start_time, start_time, 0),
    PB_FIELD(  2, UINT32  , OPTIONAL, STATIC  , OTHER, SyncResponse_Alarm, end_time, start_time, 0),
    PB_FIELD(  3, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_Alarm, ringtone_id, end_time, &SyncResponse_Alarm_ringtone_id_default),
    PB_FIELD(  4, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_Alarm, ring_offset_from_now_in_second, ringtone_id, 0),
    PB_FIELD(  5, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_Alarm, ring_duration_in_second, ring_offset_from_now_in_second, 0),
    PB_LAST_FIELD
};

const pb_field_t SyncResponse_PairingAction_fields[3] = {
    PB_FIELD(  1, STRING  , OPTIONAL, CALLBACK, FIRST, SyncResponse_PairingAction, ssid, ssid, 0),
    PB_FIELD(  2, ENUM    , OPTIONAL, STATIC  , OTHER, SyncResponse_PairingAction, type, ssid, 0),
    PB_LAST_FIELD
};

const pb_field_t SyncResponse_WhiteNoise_fields[4] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, SyncResponse_WhiteNoise, start_time, start_time, 0),
    PB_FIELD(  2, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_WhiteNoise, end_time, start_time, 0),
    PB_FIELD(  3, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_WhiteNoise, sound_id, end_time, 0),
    PB_LAST_FIELD
};

const pb_field_t SyncResponse_FlashAction_fields[9] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, SyncResponse_FlashAction, red, red, 0),
    PB_FIELD(  2, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, green, red, 0),
    PB_FIELD(  3, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, blue, green, 0),
    PB_FIELD(  4, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, delay_milliseconds, blue, 0),
    PB_FIELD(  5, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, fade_in, delay_milliseconds, 0),
    PB_FIELD(  6, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, fade_out, fade_in, 0),
    PB_FIELD(  7, BOOL    , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, rotate, fade_out, 0),
    PB_FIELD(  8, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_FlashAction, alpha, rotate, 0),
    PB_LAST_FIELD
};

const pb_field_t SyncResponse_LEDAction_fields[6] = {
    PB_FIELD(  1, ENUM    , OPTIONAL, STATIC  , FIRST, SyncResponse_LEDAction, type, type, 0),
    PB_FIELD(  2, STRING  , OPTIONAL, CALLBACK, OTHER, SyncResponse_LEDAction, url, type, 0),
    PB_FIELD(  3, UINT32  , OPTIONAL, STATIC  , OTHER, SyncResponse_LEDAction, color, url, 0),
    PB_FIELD(  4, UINT32  , OPTIONAL, STATIC  , OTHER, SyncResponse_LEDAction, alt_color, color, 0),
    PB_FIELD(  6, INT32   , OPTIONAL, STATIC  , OTHER, SyncResponse_LEDAction, duration_seconds, alt_color, 0),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(SyncResponse, alarm) < 65536 && pb_membersize(SyncResponse, pairing_action) < 65536 && pb_membersize(SyncResponse, white_noise) < 65536 && pb_membersize(SyncResponse, flash_action) < 65536 && pb_membersize(SyncResponse, files) < 65536 && pb_membersize(SyncResponse, audio_control) < 65536 && pb_membersize(SyncResponse, led_action) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_SyncResponse_SyncResponse_FileDownload_SyncResponse_Alarm_SyncResponse_PairingAction_SyncResponse_WhiteNoise_SyncResponse_FlashAction_SyncResponse_LEDAction)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(SyncResponse, alarm) < 256 && pb_membersize(SyncResponse, pairing_action) < 256 && pb_membersize(SyncResponse, white_noise) < 256 && pb_membersize(SyncResponse, flash_action) < 256 && pb_membersize(SyncResponse, files) < 256 && pb_membersize(SyncResponse, audio_control) < 256 && pb_membersize(SyncResponse, led_action) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_SyncResponse_SyncResponse_FileDownload_SyncResponse_Alarm_SyncResponse_PairingAction_SyncResponse_WhiteNoise_SyncResponse_FlashAction_SyncResponse_LEDAction)
#endif


