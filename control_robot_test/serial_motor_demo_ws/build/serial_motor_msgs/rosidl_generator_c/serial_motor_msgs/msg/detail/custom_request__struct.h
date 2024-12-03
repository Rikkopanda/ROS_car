// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serial_motor_msgs:msg/CustomRequest.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__STRUCT_H_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'str'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CustomRequest in the package serial_motor_msgs.
typedef struct serial_motor_msgs__msg__CustomRequest
{
  rosidl_runtime_c__String str;
} serial_motor_msgs__msg__CustomRequest;

// Struct for a sequence of serial_motor_msgs__msg__CustomRequest.
typedef struct serial_motor_msgs__msg__CustomRequest__Sequence
{
  serial_motor_msgs__msg__CustomRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_msgs__msg__CustomRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__STRUCT_H_
