import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.msg import SteerCommand, DriveCommand
from sensor_msgs.msg import Joy
import math

class JoystickController(Node):
	def __init__(self):
		super().__init__('joystick_controller')

		# Publisher for steer and drive commands
		self.steer_pub = self.create_publisher(SteerCommand, 'steer_command', 10)
		self.drive_pub = self.create_publisher(DriveCommand, 'drive_command', 10)

		# Subscription to joystick input (sensor_msgs/Joy)
		self.joystick_sub = self.create_subscription(Joy, 'joy', self.joystick_callback, 10)

		# Configuration for joystick axes and buttons
		self.steering_axis = 0  # Left stick horizontal
		self.drive_axis = 5    # Right trigger (axis range: -1 to 1)
		self.exit_button = 9   # Button to exit or stop the joystick control

		self.get_logger().info("Joystick Controller Node Initialized")
		
	def joystick_callback(self, msg: Joy):
		"""
		Callback to process joystick messages and publish steering and driving commands.
		"""
		# Read joystick inputs
		if len(msg.axes) > self.drive_axis and len(msg.axes) > self.steering_axis:
			steer_value = msg.axes[self.steering_axis]
			drive_value = msg.axes[self.drive_axis]

			# Map steering and driving to percentage values (0-100%)
			steer_percentage = int(((steer_value + 1.0) / 2.0) * 100)
			drive_percentage = int(((drive_value + 1.0) / 2.0) * 100)
			drive_percentage = drive_percentage - 100
			drive_percentage = drive_percentage * -1
			drive_percentage += 30
			# Publish steer command
			steer_msg = SteerCommand()
			steer_msg.steer_percentage = steer_percentage
			self.steer_pub.publish(steer_msg)

			# Publish drive command
			drive_msg = DriveCommand()
			drive_msg.drive_percentage = drive_percentage
			self.drive_pub.publish(drive_msg)

			self.get_logger().info(f"Steering: {steer_percentage}%, Drive: {drive_percentage}%")

		# Exit condition
		if len(msg.buttons) > self.exit_button and msg.buttons[self.exit_button] == 1:
			self.get_logger().info("Exit button pressed. Stopping joystick control.")
			rclpy.shutdown()
   
def main(args=None):
    rclpy.init(args=args)
    joystick_controller = JoystickController()

    rclpy.spin(joystick_controller)
    joystick_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()