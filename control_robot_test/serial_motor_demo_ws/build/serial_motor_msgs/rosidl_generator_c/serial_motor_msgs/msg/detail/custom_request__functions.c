// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serial_motor_msgs:msg/CustomRequest.idl
// generated code does not contain a copyright notice
#include "serial_motor_msgs/msg/detail/custom_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `str`
#include "rosidl_runtime_c/string_functions.h"

bool
serial_motor_msgs__msg__CustomRequest__init(serial_motor_msgs__msg__CustomRequest * msg)
{
  if (!msg) {
    return false;
  }
  // str
  if (!rosidl_runtime_c__String__init(&msg->str)) {
    serial_motor_msgs__msg__CustomRequest__fini(msg);
    return false;
  }
  return true;
}

void
serial_motor_msgs__msg__CustomRequest__fini(serial_motor_msgs__msg__CustomRequest * msg)
{
  if (!msg) {
    return;
  }
  // str
  rosidl_runtime_c__String__fini(&msg->str);
}

bool
serial_motor_msgs__msg__CustomRequest__are_equal(const serial_motor_msgs__msg__CustomRequest * lhs, const serial_motor_msgs__msg__CustomRequest * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->str), &(rhs->str)))
  {
    return false;
  }
  return true;
}

bool
serial_motor_msgs__msg__CustomRequest__copy(
  const serial_motor_msgs__msg__CustomRequest * input,
  serial_motor_msgs__msg__CustomRequest * output)
{
  if (!input || !output) {
    return false;
  }
  // str
  if (!rosidl_runtime_c__String__copy(
      &(input->str), &(output->str)))
  {
    return false;
  }
  return true;
}

serial_motor_msgs__msg__CustomRequest *
serial_motor_msgs__msg__CustomRequest__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_msgs__msg__CustomRequest * msg = (serial_motor_msgs__msg__CustomRequest *)allocator.allocate(sizeof(serial_motor_msgs__msg__CustomRequest), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_msgs__msg__CustomRequest));
  bool success = serial_motor_msgs__msg__CustomRequest__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
serial_motor_msgs__msg__CustomRequest__destroy(serial_motor_msgs__msg__CustomRequest * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    serial_motor_msgs__msg__CustomRequest__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
serial_motor_msgs__msg__CustomRequest__Sequence__init(serial_motor_msgs__msg__CustomRequest__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_msgs__msg__CustomRequest * data = NULL;

  if (size) {
    data = (serial_motor_msgs__msg__CustomRequest *)allocator.zero_allocate(size, sizeof(serial_motor_msgs__msg__CustomRequest), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_msgs__msg__CustomRequest__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_msgs__msg__CustomRequest__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
serial_motor_msgs__msg__CustomRequest__Sequence__fini(serial_motor_msgs__msg__CustomRequest__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      serial_motor_msgs__msg__CustomRequest__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

serial_motor_msgs__msg__CustomRequest__Sequence *
serial_motor_msgs__msg__CustomRequest__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_msgs__msg__CustomRequest__Sequence * array = (serial_motor_msgs__msg__CustomRequest__Sequence *)allocator.allocate(sizeof(serial_motor_msgs__msg__CustomRequest__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_msgs__msg__CustomRequest__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
serial_motor_msgs__msg__CustomRequest__Sequence__destroy(serial_motor_msgs__msg__CustomRequest__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    serial_motor_msgs__msg__CustomRequest__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
serial_motor_msgs__msg__CustomRequest__Sequence__are_equal(const serial_motor_msgs__msg__CustomRequest__Sequence * lhs, const serial_motor_msgs__msg__CustomRequest__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!serial_motor_msgs__msg__CustomRequest__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
serial_motor_msgs__msg__CustomRequest__Sequence__copy(
  const serial_motor_msgs__msg__CustomRequest__Sequence * input,
  serial_motor_msgs__msg__CustomRequest__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(serial_motor_msgs__msg__CustomRequest);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    serial_motor_msgs__msg__CustomRequest * data =
      (serial_motor_msgs__msg__CustomRequest *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!serial_motor_msgs__msg__CustomRequest__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          serial_motor_msgs__msg__CustomRequest__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!serial_motor_msgs__msg__CustomRequest__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
