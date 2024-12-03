// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serial_motor_msgs:msg/SerialLog.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__STRUCT_H_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'serial_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SerialLog in the package serial_motor_msgs.
typedef struct serial_motor_msgs__msg__SerialLog
{
  rosidl_runtime_c__String serial_msg;
} serial_motor_msgs__msg__SerialLog;

// Struct for a sequence of serial_motor_msgs__msg__SerialLog.
typedef struct serial_motor_msgs__msg__SerialLog__Sequence
{
  serial_motor_msgs__msg__SerialLog * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_msgs__msg__SerialLog__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__STRUCT_H_
