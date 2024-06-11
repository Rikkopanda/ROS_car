// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from serial_motor_msgs:msg/SerialLog.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "serial_motor_msgs/msg/detail/serial_log__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace serial_motor_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SerialLog_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) serial_motor_msgs::msg::SerialLog(_init);
}

void SerialLog_fini_function(void * message_memory)
{
  auto typed_message = static_cast<serial_motor_msgs::msg::SerialLog *>(message_memory);
  typed_message->~SerialLog();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SerialLog_message_member_array[1] = {
  {
    "serial_msg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(serial_motor_msgs::msg::SerialLog, serial_msg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SerialLog_message_members = {
  "serial_motor_msgs::msg",  // message namespace
  "SerialLog",  // message name
  1,  // number of fields
  sizeof(serial_motor_msgs::msg::SerialLog),
  SerialLog_message_member_array,  // message members
  SerialLog_init_function,  // function to initialize message memory (memory has to be allocated)
  SerialLog_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SerialLog_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SerialLog_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace serial_motor_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<serial_motor_msgs::msg::SerialLog>()
{
  return &::serial_motor_msgs::msg::rosidl_typesupport_introspection_cpp::SerialLog_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, serial_motor_msgs, msg, SerialLog)() {
  return &::serial_motor_msgs::msg::rosidl_typesupport_introspection_cpp::SerialLog_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
