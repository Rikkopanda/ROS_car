// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serial_motor_msgs:msg/SerialLog.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__BUILDER_HPP_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "serial_motor_msgs/msg/detail/serial_log__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace serial_motor_msgs
{

namespace msg
{

namespace builder
{

class Init_SerialLog_serial_msg
{
public:
  Init_SerialLog_serial_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::serial_motor_msgs::msg::SerialLog serial_msg(::serial_motor_msgs::msg::SerialLog::_serial_msg_type arg)
  {
    msg_.serial_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_msgs::msg::SerialLog msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_msgs::msg::SerialLog>()
{
  return serial_motor_msgs::msg::builder::Init_SerialLog_serial_msg();
}

}  // namespace serial_motor_msgs

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__BUILDER_HPP_
