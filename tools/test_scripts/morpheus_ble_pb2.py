# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: morpheus_ble.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='morpheus_ble.proto',
  package='',
  serialized_pb='\n\x12morpheus_ble.proto\"\xbe\x08\n\x0fMorpheusCommand\x12\x0f\n\x07version\x18\x01 \x02(\x05\x12*\n\x04type\x18\x02 \x02(\x0e\x32\x1c.MorpheusCommand.CommandType\x12\x10\n\x08\x64\x65viceId\x18\x03 \x01(\t\x12\x11\n\taccountId\x18\x04 \x01(\t\x12\x19\n\x05\x65rror\x18\x05 \x01(\x0e\x32\n.ErrorType\x12\x10\n\x08wifiName\x18\x06 \x01(\t\x12\x10\n\x08wifiSSID\x18\x07 \x01(\t\x12\x14\n\x0cwifiPassword\x18\x08 \x01(\t\x12\x14\n\x0c\x62\x61tteryLevel\x18\t \x01(\x05\x12\x0e\n\x06uptime\x18\n \x01(\x05\x12\x12\n\nmotionData\x18\x0b \x01(\x05\x12\x1b\n\x13motionDataEntrypted\x18\x0c \x01(\x0c\x12\x17\n\x0f\x66irmwareVersion\x18\r \x01(\x05\"\x83\x06\n\x0b\x43ommandType\x12\x1d\n\x19MORPHEUS_COMMAND_SET_TIME\x10\x00\x12\x1d\n\x19MORPHEUS_COMMAND_GET_TIME\x10\x01\x12&\n\"MORPHEUS_COMMAND_SET_WIFI_ENDPOINT\x10\x02\x12&\n\"MORPHEUS_COMMAND_GET_WIFI_ENDPOINT\x10\x03\x12\x1f\n\x1bMORPHEUS_COMMAND_SET_ALARMS\x10\x04\x12\x1f\n\x1bMORPHEUS_COMMAND_GET_ALARMS\x10\x05\x12+\n\'MORPHEUS_COMMAND_SWITCH_TO_PAIRING_MODE\x10\x06\x12*\n&MORPHEUS_COMMAND_SWITCH_TO_NORMAL_MODE\x10\x07\x12#\n\x1fMORPHEUS_COMMAND_START_WIFISCAN\x10\x08\x12\"\n\x1eMORPHEUS_COMMAND_STOP_WIFISCAN\x10\t\x12\"\n\x1eMORPHEUS_COMMAND_GET_DEVICE_ID\x10\n\x12(\n$MORPHEUS_COMMAND_EREASE_PAIRED_PHONE\x10\x0b\x12\x1e\n\x1aMORPHEUS_COMMAND_PAIR_PILL\x10\x0c\x12\x1a\n\x16MORPHEUS_COMMAND_ERROR\x10\r\x12\x1f\n\x1bMORPHEUS_COMMAND_PAIR_SENSE\x10\x0e\x12 \n\x1cMORPHEUS_COMMAND_UNPAIR_PILL\x10\x0f\x12\'\n#MORPHEUS_COMMAND_MORPHEUS_DFU_BEGIN\x10\x10\x12\x1e\n\x1aMORPHEUS_COMMAND_PILL_DATA\x10\x11\x12#\n\x1fMORPHEUS_COMMAND_PILL_HEARTBEAT\x10\x12\x12#\n\x1fMORPHEUS_COMMAND_PILL_DFU_BEGIN\x10\x13\x12\"\n\x1eMORPHEUS_COMMAND_FACTORY_RESET\x10\x14*\xfb\x01\n\tErrorType\x12\x0c\n\x08TIME_OUT\x10\x00\x12\x11\n\rNETWORK_ERROR\x10\x01\x12\x19\n\x15\x44\x45VICE_ALREADY_PAIRED\x10\x02\x12\x17\n\x13INTERNAL_DATA_ERROR\x10\x03\x12\x18\n\x14\x44\x45VICE_DATABASE_FULL\x10\x04\x12\x14\n\x10\x44\x45VICE_NO_MEMORY\x10\x05\x12\x1d\n\x19INTERNAL_OPERATION_FAILED\x10\x06\x12\x18\n\x14NO_ENDPOINT_IN_RANGE\x10\x07\x12\x19\n\x15WLAN_CONNECTION_ERROR\x10\x08\x12\x15\n\x11\x46\x41IL_TO_OBTAIN_IP\x10\t')

_ERRORTYPE = _descriptor.EnumDescriptor(
  name='ErrorType',
  full_name='ErrorType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='TIME_OUT', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='NETWORK_ERROR', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEVICE_ALREADY_PAIRED', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='INTERNAL_DATA_ERROR', index=3, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEVICE_DATABASE_FULL', index=4, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEVICE_NO_MEMORY', index=5, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='INTERNAL_OPERATION_FAILED', index=6, number=6,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='NO_ENDPOINT_IN_RANGE', index=7, number=7,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='WLAN_CONNECTION_ERROR', index=8, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FAIL_TO_OBTAIN_IP', index=9, number=9,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=1112,
  serialized_end=1363,
)

ErrorType = enum_type_wrapper.EnumTypeWrapper(_ERRORTYPE)
TIME_OUT = 0
NETWORK_ERROR = 1
DEVICE_ALREADY_PAIRED = 2
INTERNAL_DATA_ERROR = 3
DEVICE_DATABASE_FULL = 4
DEVICE_NO_MEMORY = 5
INTERNAL_OPERATION_FAILED = 6
NO_ENDPOINT_IN_RANGE = 7
WLAN_CONNECTION_ERROR = 8
FAIL_TO_OBTAIN_IP = 9


_MORPHEUSCOMMAND_COMMANDTYPE = _descriptor.EnumDescriptor(
  name='CommandType',
  full_name='MorpheusCommand.CommandType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_SET_TIME', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_GET_TIME', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_SET_WIFI_ENDPOINT', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_GET_WIFI_ENDPOINT', index=3, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_SET_ALARMS', index=4, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_GET_ALARMS', index=5, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_SWITCH_TO_PAIRING_MODE', index=6, number=6,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_SWITCH_TO_NORMAL_MODE', index=7, number=7,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_START_WIFISCAN', index=8, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_STOP_WIFISCAN', index=9, number=9,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_GET_DEVICE_ID', index=10, number=10,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_EREASE_PAIRED_PHONE', index=11, number=11,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_PAIR_PILL', index=12, number=12,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_ERROR', index=13, number=13,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_PAIR_SENSE', index=14, number=14,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_UNPAIR_PILL', index=15, number=15,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_MORPHEUS_DFU_BEGIN', index=16, number=16,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_PILL_DATA', index=17, number=17,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_PILL_HEARTBEAT', index=18, number=18,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_PILL_DFU_BEGIN', index=19, number=19,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MORPHEUS_COMMAND_FACTORY_RESET', index=20, number=20,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=338,
  serialized_end=1109,
)


_MORPHEUSCOMMAND = _descriptor.Descriptor(
  name='MorpheusCommand',
  full_name='MorpheusCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='version', full_name='MorpheusCommand.version', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='type', full_name='MorpheusCommand.type', index=1,
      number=2, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='deviceId', full_name='MorpheusCommand.deviceId', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='accountId', full_name='MorpheusCommand.accountId', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='error', full_name='MorpheusCommand.error', index=4,
      number=5, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='wifiName', full_name='MorpheusCommand.wifiName', index=5,
      number=6, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='wifiSSID', full_name='MorpheusCommand.wifiSSID', index=6,
      number=7, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='wifiPassword', full_name='MorpheusCommand.wifiPassword', index=7,
      number=8, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='batteryLevel', full_name='MorpheusCommand.batteryLevel', index=8,
      number=9, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='uptime', full_name='MorpheusCommand.uptime', index=9,
      number=10, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='motionData', full_name='MorpheusCommand.motionData', index=10,
      number=11, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='motionDataEntrypted', full_name='MorpheusCommand.motionDataEntrypted', index=11,
      number=12, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value="",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='firmwareVersion', full_name='MorpheusCommand.firmwareVersion', index=12,
      number=13, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _MORPHEUSCOMMAND_COMMANDTYPE,
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=23,
  serialized_end=1109,
)

_MORPHEUSCOMMAND.fields_by_name['type'].enum_type = _MORPHEUSCOMMAND_COMMANDTYPE
_MORPHEUSCOMMAND.fields_by_name['error'].enum_type = _ERRORTYPE
_MORPHEUSCOMMAND_COMMANDTYPE.containing_type = _MORPHEUSCOMMAND;
DESCRIPTOR.message_types_by_name['MorpheusCommand'] = _MORPHEUSCOMMAND

class MorpheusCommand(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _MORPHEUSCOMMAND

  # @@protoc_insertion_point(class_scope:MorpheusCommand)


# @@protoc_insertion_point(module_scope)
