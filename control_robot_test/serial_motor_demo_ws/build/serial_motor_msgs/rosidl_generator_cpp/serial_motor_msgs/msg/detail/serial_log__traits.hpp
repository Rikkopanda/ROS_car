// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from serial_motor_msgs:msg/SerialLog.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__TRAITS_HPP_
#define SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "serial_motor_msgs/msg/detail/serial_log__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace serial_motor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SerialLog & msg,
  std::ostream & out)
{
  out << "{";
  // member: serial_msg
  {
    out << "serial_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SerialLog & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: serial_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SerialLog & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace serial_motor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use serial_motor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const serial_motor_msgs::msg::SerialLog & msg,
  std::ostream & out, size_t indentation = 0)
{
  serial_motor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use serial_motor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const serial_motor_msgs::msg::SerialLog & msg)
{
  return serial_motor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<serial_motor_msgs::msg::SerialLog>()
{
  return "serial_motor_msgs::msg::SerialLog";
}

template<>
inline const char * name<serial_motor_msgs::msg::SerialLog>()
{
  return "serial_motor_msgs/msg/SerialLog";
}

template<>
struct has_fixed_size<serial_motor_msgs::msg::SerialLog>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<serial_motor_msgs::msg::SerialLog>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<serial_motor_msgs::msg::SerialLog>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SERIAL_MOTOR_MSGS__MSG__DETAIL__SERIAL_LOG__TRAITS_HPP_
