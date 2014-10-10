/* Automatically generated nanopb header */
/* Generated by nanopb-0.2.8 at Thu Oct  9 18:06:24 2014. */

#ifndef _PB_PERIODIC_PB_H_
#define _PB_PERIODIC_PB_H_
#include <pb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
/* Struct definitions */
typedef struct _periodic_data_pill_data {
    bool has_firmwareVersion;
    int32_t firmwareVersion;
    pb_callback_t motionDataEncrypted;
    pb_callback_t deviceId;
    bool has_batteryLevel;
    int32_t batteryLevel;
    bool has_uptime;
    int32_t uptime;
    bool has_motionData;
    int32_t motionData;
} periodic_data_pill_data;

typedef struct _periodic_data {
    bool has_unix_time;
    int32_t unix_time;
    bool has_light;
    int32_t light;
    bool has_temperature;
    int32_t temperature;
    bool has_humidity;
    int32_t humidity;
    bool has_dust;
    int32_t dust;
    pb_callback_t name;
    pb_callback_t mac;
    bool has_light_variability;
    int32_t light_variability;
    bool has_light_tonality;
    int32_t light_tonality;
    bool has_firmware_version;
    int32_t firmware_version;
    pb_callback_t pills;
} periodic_data;

/* Default values for struct fields */

/* Field tags (for use in manual encoding/decoding) */
#define periodic_data_pill_data_deviceId_tag     3
#define periodic_data_pill_data_batteryLevel_tag 9
#define periodic_data_pill_data_uptime_tag       10
#define periodic_data_pill_data_motionData_tag   11
#define periodic_data_pill_data_motionDataEncrypted_tag 2
#define periodic_data_pill_data_firmwareVersion_tag 1
#define periodic_data_unix_time_tag              1
#define periodic_data_light_tag                  2
#define periodic_data_temperature_tag            3
#define periodic_data_humidity_tag               4
#define periodic_data_dust_tag                   5
#define periodic_data_name_tag                   6
#define periodic_data_mac_tag                    7
#define periodic_data_light_variability_tag      8
#define periodic_data_light_tonality_tag         9
#define periodic_data_firmware_version_tag       10
#define periodic_data_pills_tag                  11

/* Struct field encoding specification for nanopb */
extern const pb_field_t periodic_data_fields[12];
extern const pb_field_t periodic_data_pill_data_fields[7];

/* Maximum encoded size of messages (where known) */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
