#include <string.h>

#include "ble_cmd.h"
#include "ble_proto.h"

#include "uartstdio.h"

#include "wifi_cmd.h"
#include "spi_cmd.h"

static bool _encode_string_fields(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
    char* str = *arg;
    if(!str)
    {
        return false;
    }

    //write tag
    if (!pb_encode_tag(stream, PB_WT_STRING, field->tag)) {
        return 0;
    }

    return pb_encode_string(stream, (uint8_t*)str, strlen(str));
}


static bool _decode_string_field(pb_istream_t *stream, const pb_field_t *field, void **arg)
{
    /* We could read block-by-block to avoid the large buffer... */
    if (stream->bytes_left > MAX_STRING_LEN - 1)
    {
        return false;
    }
    
    uint8_t* str = malloc(stream->bytes_left + 1);
    if(!str)
    {
        return false;
    }

    memset(str, 0, stream->bytes_left + 1);
    if (!pb_read(stream, str, stream->bytes_left))
    {
        return false;
    }
    *arg = str;

    return true;
}




void on_morpheus_protobuf_arrival(uint8_t* protobuf, size_t len)
{
    if(!protobuf)
    {
        UARTprintf("Inavlid parameter.\r\n");
        return;
    }

    MorpheusCommand command;
    memset(&command, 0, sizeof(command));

    
    command.accountId.funcs.decode = _decode_string_field;
    command.accountId.arg = NULL;

    command.deviceId.funcs.decode = _decode_string_field;
    command.deviceId.arg = NULL;

    command.wifiName.funcs.decode = _decode_string_field;
    command.wifiName.arg = NULL;

    command.wifiSSID.funcs.decode = _decode_string_field;
    command.wifiSSID.arg = NULL;

    command.wifiPassword.funcs.decode = _decode_string_field;
    command.wifiPassword.arg = NULL;

    pb_istream_t stream = pb_istream_from_buffer(protobuf, len);
    bool status = pb_decode(&stream, MorpheusCommand_fields, &command);
    

    if (!status)
    {
        UARTprintf("Decoding protobuf failed, error: ");
        UARTprintf(PB_GET_ERROR(&stream));
        UARTprintf("\r\n");
    }else{

        on_ble_protobuf_command(&command);
    }

    free_protobuf_command(&command);
    
}

static MorpheusCommand* _assign_encode_funcs(MorpheusCommand* command)
{
    if(command->accountId.arg != NULL && command->accountId.funcs.encode == NULL)
    {
        command->accountId.funcs.encode = _encode_string_fields;
    }

    if(command->deviceId.arg != NULL && command->deviceId.funcs.encode == NULL)
    {
        command->deviceId.funcs.encode = _encode_string_fields;
    }

    if(command->wifiName.arg != NULL && command->wifiName.funcs.encode == NULL)
    {
        command->wifiName.funcs.encode = _encode_string_fields;
    }

    if(command->wifiSSID.arg != NULL && command->wifiSSID.funcs.encode == NULL)
    {
        command->wifiSSID.funcs.encode = _encode_string_fields;
    }

    if(command->wifiPassword.arg != NULL && command->wifiPassword.funcs.encode == NULL)
    {
        command->wifiPassword.funcs.encode = _encode_string_fields;
    }

    return command;
}

bool ble_reply_protobuf_error(ErrorType error_type)
{
	uint8_t _error_buf[20];
    MorpheusCommand morpheus_command;
    memset(&morpheus_command, 0, sizeof(morpheus_command));
    morpheus_command.type = MorpheusCommand_CommandType_MORPHEUS_COMMAND_ERROR;
    morpheus_command.version = PROTOBUF_VERSION;

    morpheus_command.has_error = true;
    morpheus_command.error = error_type;

    memset(_error_buf, 0, sizeof(_error_buf));

    pb_ostream_t stream = pb_ostream_from_buffer(_error_buf, sizeof(_error_buf));
    bool status = pb_encode(&stream, MorpheusCommand_fields, &morpheus_command);
    
    if(status)
    {
        size_t protobuf_len = stream.bytes_written;
        spi_write(protobuf_len, _error_buf);
    }else{
        UARTprintf("encode protobuf failed: %s\r\n", PB_GET_ERROR(&stream));
    }

    return status;
}


bool ble_send_protobuf(MorpheusCommand* command)
{
    if(!command){
        UARTprintf("Inavlid parameter.\r\n");
        return false;
    }


    _assign_encode_funcs(command);


    pb_ostream_t stream = {0};
    pb_encode(&stream, MorpheusCommand_fields, command);

    uint8_t* heap_page = malloc(stream.bytes_written);
    if(!heap_page)
    {
        UARTprintf("Not enough memory.\r\n");
        return false;
    }

    memset(heap_page, 0, stream.bytes_written);
    stream = pb_ostream_from_buffer(heap_page, stream.bytes_written);

    bool status = pb_encode(&stream, MorpheusCommand_fields, command);
    
    if(status)
    {
        size_t protobuf_len = stream.bytes_written;
        spi_write(protobuf_len, heap_page);

    }else{
        UARTprintf("encode protobuf failed: ");
        UARTprintf(PB_GET_ERROR(&stream));
        UARTprintf("\r\n");
    }
    free(heap_page);

    return status;
}


void free_protobuf_command(MorpheusCommand* command)
{
    if(!command)
    {
        UARTprintf("Inavlid parameter.\r\n");
        return;
    }

    if(!command->accountId.arg)
    {
        free(command->accountId.arg);
        command->accountId.arg = NULL;
    }

    if(!command->deviceId.arg)
    {
        free(command->deviceId.arg);
        command->deviceId.arg = NULL;
    }

    if(!command->wifiName.arg)
    {
        free(command->wifiName.arg);
        command->wifiName.arg = NULL;
    }

    if(!command->wifiSSID.arg)
    {
        free(command->wifiSSID.arg);
        command->wifiSSID.arg = NULL;
    }

    if(!command->wifiPassword.arg)
    {
        free(command->wifiPassword.arg);
        command->wifiPassword.arg = NULL;
    }
}
