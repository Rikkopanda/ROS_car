// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from serial_motor_msgs:msg/CustomRequest.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__STRUCT_HPP_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__serial_motor_msgs__msg__CustomRequest __attribute__((deprecated))
#else
# define DEPRECATED__serial_motor_msgs__msg__CustomRequest __declspec(deprecated)
#endif

namespace serial_motor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CustomRequest_
{
  using Type = CustomRequest_<ContainerAllocator>;

  explicit CustomRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->str = "";
    }
  }

  explicit CustomRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : str(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->str = "";
    }
  }

  // field types and members
  using _str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _str_type str;

  // setters for named parameter idiom
  Type & set__str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->str = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    serial_motor_msgs::msg::CustomRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const serial_motor_msgs::msg::CustomRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      serial_motor_msgs::msg::CustomRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      serial_motor_msgs::msg::CustomRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__serial_motor_msgs__msg__CustomRequest
    std::shared_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__serial_motor_msgs__msg__CustomRequest
    std::shared_ptr<serial_motor_msgs::msg::CustomRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CustomRequest_ & other) const
  {
    if (this->str != other.str) {
      return false;
    }
    return true;
  }
  bool operator!=(const CustomRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CustomRequest_

// alias to use template instance with default allocator
using CustomRequest =
  serial_motor_msgs::msg::CustomRequest_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace serial_motor_msgs

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__STRUCT_HPP_
