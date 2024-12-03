// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serial_motor_msgs:msg/CustomRequest.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__BUILDER_HPP_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serial_motor_msgs/msg/detail/custom_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serial_motor_msgs
{

namespace msg
{

namespace builder
{

class Init_CustomRequest_str
{
public:
  Init_CustomRequest_str()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serial_motor_msgs::msg::CustomRequest str(::serial_motor_msgs::msg::CustomRequest::_str_type arg)
  {
    msg_.str = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_msgs::msg::CustomRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_msgs::msg::CustomRequest>()
{
  return serial_motor_msgs::msg::builder::Init_CustomRequest_str();
}

}  // namespace serial_motor_msgs

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__CUSTOM_REQUEST__BUILDER_HPP_
