/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.1 at Mon Aug 29 10:49:31 2016. */

#ifndef PB_MORPHEUS_BLE_PB_H_INCLUDED
#define PB_MORPHEUS_BLE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _ErrorType {
    ErrorType_TIME_OUT = 0,
    ErrorType_NETWORK_ERROR = 1,
    ErrorType_DEVICE_ALREADY_PAIRED = 2,
    ErrorType_INTERNAL_DATA_ERROR = 3,
    ErrorType_DEVICE_DATABASE_FULL = 4,
    ErrorType_DEVICE_NO_MEMORY = 5,
    ErrorType_INTERNAL_OPERATION_FAILED = 6,
    ErrorType_NO_ENDPOINT_IN_RANGE = 7,
    ErrorType_WLAN_CONNECTION_ERROR = 8,
    ErrorType_FAIL_TO_OBTAIN_IP = 9,
    ErrorType_WLAN_ENDPOINT_DELETE_FAILED = 10,
    ErrorType_INVALID_ACCOUNT_ID = 11,
    ErrorType_FORCE_DATA_PUSH_FAILED = 12,
    ErrorType_PROTOBUF_ENCODE_FAILED = 13,
    ErrorType_PROTOBUF_DECODE_FAILED = 14,
    ErrorType_SERVER_CONNECTION_TIMEOUT = 15
} ErrorType;

typedef enum _wifi_connection_state {
    wifi_connection_state_NO_WLAN_CONNECTED = 0,
    wifi_connection_state_WLAN_CONNECTING = 1,
    wifi_connection_state_WLAN_CONNECTED = 2,
    wifi_connection_state_IP_RETRIEVED = 3,
    wifi_connection_state_DNS_RESOLVED = 4,
    wifi_connection_state_SOCKET_CONNECTED = 5,
    wifi_connection_state_REQUEST_SENT = 6,
    wifi_connection_state_CONNECTED = 7,
    wifi_connection_state_SSL_FAIL = 8,
    wifi_connection_state_HELLO_KEY_FAIL = 9,
    wifi_connection_state_DNS_FAILED = 10,
    wifi_connection_state_CONNECT_FAILED = 11
} wifi_connection_state;

typedef enum _wifi_endpoint_sec_type {
    wifi_endpoint_sec_type_SL_SCAN_SEC_TYPE_OPEN = 0,
    wifi_endpoint_sec_type_SL_SCAN_SEC_TYPE_WEP = 1,
    wifi_endpoint_sec_type_SL_SCAN_SEC_TYPE_WPA = 2,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_WPS_PBC = 3,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_WPS_PIN = 4,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_WPA_ENT = 5,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_P2P_PBC = 6,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_P2P_PIN_KEYPAD = 7,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_P2P_PIN_DISPLAY = 8,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_P2P_PIN_AUTO = 9,
    wifi_endpoint_sec_type_SL_WLAN_SEC_TYPE_WEP_SHARED = 10
} wifi_endpoint_sec_type;

typedef enum _MorpheusCommand_CommandType {
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SET_TIME = 0,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_GET_TIME = 1,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SET_WIFI_ENDPOINT = 2,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_GET_WIFI_ENDPOINT = 3,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SET_ALARMS = 4,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_GET_ALARMS = 5,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SWITCH_TO_PAIRING_MODE = 6,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SWITCH_TO_NORMAL_MODE = 7,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_START_WIFISCAN = 8,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_STOP_WIFISCAN = 9,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_GET_DEVICE_ID = 10,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_ERASE_PAIRED_PHONE = 11,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PAIR_PILL = 12,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_ERROR = 13,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PAIR_SENSE = 14,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_UNPAIR_PILL = 15,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_MORPHEUS_DFU_BEGIN = 16,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PILL_DATA = 17,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PILL_HEARTBEAT = 18,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PILL_DFU_BEGIN = 19,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_FACTORY_RESET = 20,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PILL_SHAKES = 21,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SYNC_DEVICE_ID = 22,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PHONE_BLE_CONNECTED = 23,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PHONE_BLE_BONDED = 24,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_LED_BUSY = 25,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_LED_TRIPPY = 26,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_LED_OPERATION_FAILED = 27,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SCAN_WIFI = 28,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_GET_NEXT_WIFI_AP = 29,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_LED_OPERATION_SUCCESS = 30,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PUSH_DATA_AFTER_SET_TIMEZONE = 31,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SET_COUNTRY_CODE = 32,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_SET_SERVER_IP = 33,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_CONNECTION_STATE = 34,
    MorpheusCommand_CommandType_MORPHEUS_COMMAND_PILL_PROX_DATA = 35
} MorpheusCommand_CommandType;

/* Struct definitions */
typedef struct _batched_pill_data {
    pb_callback_t pills;
    pb_callback_t device_id;
    pb_callback_t prox;
} batched_pill_data;

typedef PB_BYTES_ARRAY_T(20) pill_data_motion_data_entrypted_t;

typedef struct _pill_data {
    char device_id[17];
    bool has_battery_level;
    int32_t battery_level;
    bool has_uptime;
    int32_t uptime;
    bool has_motion_data_entrypted;
    pill_data_motion_data_entrypted_t motion_data_entrypted;
    bool has_firmware_version;
    int32_t firmware_version;
    uint64_t timestamp;
    bool has_rssi;
    int32_t rssi;
} pill_data;

typedef struct _wifi_endpoint {
    pb_callback_t ssid;
    pb_callback_t bssid;
    int32_t rssi;
    wifi_endpoint_sec_type security_type;
} wifi_endpoint;

typedef PB_BYTES_ARRAY_T(16) MorpheusCommand_aes_key_t;

typedef struct _MorpheusCommand {
    int32_t version;
    MorpheusCommand_CommandType type;
    pb_callback_t deviceId;
    pb_callback_t accountId;
    bool has_error;
    ErrorType error;
    pb_callback_t wifiName;
    pb_callback_t wifiSSID;
    pb_callback_t wifiPassword;
    bool has_firmwareVersion;
    int32_t firmwareVersion;
    pb_callback_t wifi_scan_result;
    bool has_security_type;
    wifi_endpoint_sec_type security_type;
    bool has_pill_data;
    pill_data pill_data;
    bool has_wifi_connection_state;
    wifi_connection_state wifi_connection_state;
    bool has_ble_bond_count;
    int32_t ble_bond_count;
    bool has_country_code;
    char country_code[3];
    bool has_aes_key;
    MorpheusCommand_aes_key_t aes_key;
    bool has_top_version;
    char top_version[16];
    bool has_server_ip;
    uint32_t server_ip;
    bool has_socket_error_code;
    uint32_t socket_error_code;
    bool has_http_response_code;
    char http_response_code[16];
    bool has_app_version;
    int32_t app_version;
} MorpheusCommand;

/* Default values for struct fields */

/* Initializer values for message structs */
#define wifi_endpoint_init_default               {{{NULL}, NULL}, {{NULL}, NULL}, 0, (wifi_endpoint_sec_type)0}
#define pill_data_init_default                   {"", false, 0, false, 0, false, {0, {0}}, false, 0, 0, false, 0}
#define MorpheusCommand_init_default             {0, (MorpheusCommand_CommandType)0, {{NULL}, NULL}, {{NULL}, NULL}, false, (ErrorType)0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, false, (wifi_endpoint_sec_type)0, false, pill_data_init_default, false, (wifi_connection_state)0, false, 0, false, "", false, {0, {0}}, false, "", false, 0, false, 0, false, "", false, 0}
#define batched_pill_data_init_default           {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define wifi_endpoint_init_zero                  {{{NULL}, NULL}, {{NULL}, NULL}, 0, (wifi_endpoint_sec_type)0}
#define pill_data_init_zero                      {"", false, 0, false, 0, false, {0, {0}}, false, 0, 0, false, 0}
#define MorpheusCommand_init_zero                {0, (MorpheusCommand_CommandType)0, {{NULL}, NULL}, {{NULL}, NULL}, false, (ErrorType)0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, false, (wifi_endpoint_sec_type)0, false, pill_data_init_zero, false, (wifi_connection_state)0, false, 0, false, "", false, {0, {0}}, false, "", false, 0, false, 0, false, "", false, 0}
#define batched_pill_data_init_zero              {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define batched_pill_data_pills_tag              1
#define batched_pill_data_device_id_tag          2
#define batched_pill_data_prox_tag               3
#define pill_data_device_id_tag                  1
#define pill_data_battery_level_tag              2
#define pill_data_uptime_tag                     3
#define pill_data_motion_data_entrypted_tag      4
#define pill_data_firmware_version_tag           5
#define pill_data_timestamp_tag                  6
#define pill_data_rssi_tag                       7
#define wifi_endpoint_ssid_tag                   1
#define wifi_endpoint_bssid_tag                  2
#define wifi_endpoint_rssi_tag                   4
#define wifi_endpoint_security_type_tag          5
#define MorpheusCommand_version_tag              1
#define MorpheusCommand_type_tag                 2
#define MorpheusCommand_deviceId_tag             3
#define MorpheusCommand_accountId_tag            4
#define MorpheusCommand_error_tag                5
#define MorpheusCommand_wifiName_tag             6
#define MorpheusCommand_wifiSSID_tag             7
#define MorpheusCommand_wifiPassword_tag         8
#define MorpheusCommand_firmwareVersion_tag      13
#define MorpheusCommand_wifi_scan_result_tag     14
#define MorpheusCommand_security_type_tag        15
#define MorpheusCommand_pill_data_tag            16
#define MorpheusCommand_wifi_connection_state_tag 17
#define MorpheusCommand_ble_bond_count_tag       18
#define MorpheusCommand_country_code_tag         19
#define MorpheusCommand_aes_key_tag              20
#define MorpheusCommand_top_version_tag          21
#define MorpheusCommand_server_ip_tag            22
#define MorpheusCommand_socket_error_code_tag    23
#define MorpheusCommand_http_response_code_tag   24
#define MorpheusCommand_app_version_tag          25

/* Struct field encoding specification for nanopb */
extern const pb_field_t wifi_endpoint_fields[5];
extern const pb_field_t pill_data_fields[8];
extern const pb_field_t MorpheusCommand_fields[22];
extern const pb_field_t batched_pill_data_fields[4];

/* Maximum encoded size of messages (where known) */
#define pill_data_size                           96

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
