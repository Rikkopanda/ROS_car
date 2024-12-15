import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.msg import SteerCommand
from serial_motor_demo_msgs.msg import DriveCommand

class UserInputNode(Node):

    def __init__(self):
        super().__init__('user_input_node')

        # Publisher to publish user input as SteerCommand
        self.publisher_1 = self.create_publisher(SteerCommand, 'steer_command', 10)
        self.publisher_2 = self.create_publisher(DriveCommand, 'drive_command', 10)

        self.get_logger().info("User Input Node initialized. Waiting for input...")

    def publish_steer_input(self, percentage):
        msg = SteerCommand()
        msg.steer_percentage = percentage
        self.publisher_1.publish(msg)
        self.get_logger().info(f"Published steer_pwm: {percentage}")
    def publish_drive_input(self, percentage):
        msg = DriveCommand()
        msg.drive_percentage = percentage
        self.publisher_2.publish(msg)
        self.get_logger().info(f"Published steer_pwm: {percentage}")

def main(args=None):
	rclpy.init(args=args)

	user_input_node = UserInputNode()

	try:
		while rclpy.ok():
			# Get user input from stdin
			try:
				inputstr = input("Enter steer or drive percentage value (0-100%) [e.g. S30 or D30]):")
				if (inputstr.find("S", 0, 3)):
					percentage = int(inputstr[1:])
					# Publish the user input as a message
					user_input_node.publish_drive_input(percentage)
				if (inputstr.find("D", 0, 3)):
					percentage = int(inputstr[1:])
					# Publish the user input as a message
					user_input_node.publish_steer_input(percentage)
			except ValueError:
				print("Invalid input. Please enter an integer value.")

			# Keep spinning to allow callback execution if needed
			rclpy.spin_once(user_input_node, timeout_sec=0.1)

	except KeyboardInterrupt:
		user_input_node.get_logger().info("User Input Node shutting down.")

	user_input_node.destroy_node()
	rclpy.shutdown()

if __name__ == '__main__':
	main()
