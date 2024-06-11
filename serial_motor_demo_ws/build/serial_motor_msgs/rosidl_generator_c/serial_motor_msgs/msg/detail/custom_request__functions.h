// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from serial_motor_msgs:msg/CustomRequest.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__FUNCTIONS_H_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "serial_motor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "serial_motor_msgs/msg/detail/custom_request__struct.h"

/// Initialize msg/CustomRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * serial_motor_msgs__msg__CustomRequest
 * )) before or use
 * serial_motor_msgs__msg__CustomRequest__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
bool
serial_motor_msgs__msg__CustomRequest__init(serial_motor_msgs__msg__CustomRequest * msg);

/// Finalize msg/CustomRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
void
serial_motor_msgs__msg__CustomRequest__fini(serial_motor_msgs__msg__CustomRequest * msg);

/// Create msg/CustomRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * serial_motor_msgs__msg__CustomRequest__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
serial_motor_msgs__msg__CustomRequest *
serial_motor_msgs__msg__CustomRequest__create();

/// Destroy msg/CustomRequest message.
/**
 * It calls
 * serial_motor_msgs__msg__CustomRequest__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
void
serial_motor_msgs__msg__CustomRequest__destroy(serial_motor_msgs__msg__CustomRequest * msg);

/// Check for msg/CustomRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
bool
serial_motor_msgs__msg__CustomRequest__are_equal(const serial_motor_msgs__msg__CustomRequest * lhs, const serial_motor_msgs__msg__CustomRequest * rhs);

/// Copy a msg/CustomRequest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
bool
serial_motor_msgs__msg__CustomRequest__copy(
  const serial_motor_msgs__msg__CustomRequest * input,
  serial_motor_msgs__msg__CustomRequest * output);

/// Initialize array of msg/CustomRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * serial_motor_msgs__msg__CustomRequest__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
bool
serial_motor_msgs__msg__CustomRequest__Sequence__init(serial_motor_msgs__msg__CustomRequest__Sequence * array, size_t size);

/// Finalize array of msg/CustomRequest messages.
/**
 * It calls
 * serial_motor_msgs__msg__CustomRequest__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
void
serial_motor_msgs__msg__CustomRequest__Sequence__fini(serial_motor_msgs__msg__CustomRequest__Sequence * array);

/// Create array of msg/CustomRequest messages.
/**
 * It allocates the memory for the array and calls
 * serial_motor_msgs__msg__CustomRequest__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
serial_motor_msgs__msg__CustomRequest__Sequence *
serial_motor_msgs__msg__CustomRequest__Sequence__create(size_t size);

/// Destroy array of msg/CustomRequest messages.
/**
 * It calls
 * serial_motor_msgs__msg__CustomRequest__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
void
serial_motor_msgs__msg__CustomRequest__Sequence__destroy(serial_motor_msgs__msg__CustomRequest__Sequence * array);

/// Check for msg/CustomRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
bool
serial_motor_msgs__msg__CustomRequest__Sequence__are_equal(const serial_motor_msgs__msg__CustomRequest__Sequence * lhs, const serial_motor_msgs__msg__CustomRequest__Sequence * rhs);

/// Copy an array of msg/CustomRequest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_msgs
bool
serial_motor_msgs__msg__CustomRequest__Sequence__copy(
  const serial_motor_msgs__msg__CustomRequest__Sequence * input,
  serial_motor_msgs__msg__CustomRequest__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__FUNCTIONS_H_
