#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
# from rcl_interfaces.msg import Log
from std_msgs.msg import String

class DrawCircleNode(Node):
	def __init__(self):
		super().__init__("draw_circle")
		self.cmd_vel_pub_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)#cmdvel is the msgs name
		self.timer = self.create_timer(0.5, self.send_velocity_command)
		self.get_logger().info("Hello from Draw cirle node")

	def send_velocity_command(self):
		msg = Twist()
		msg.linear.x = 5.0
		msg.angular.z = 1.0
		self.cmd_vel_pub_.publish(msg)

def main(args=None):
	rclpy.init(args=args)
	node = DrawCircleNode()

	rclpy.spin(node)
	rclpy.shutdown()

if __name__ == '__main__':
	main()
