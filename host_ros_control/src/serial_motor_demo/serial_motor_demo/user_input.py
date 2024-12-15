import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.msg import SteerCommand

class UserInputNode(Node):

    def __init__(self):
        super().__init__('user_input_node')

        # Publisher to publish user input as SteerCommand
        self.publisher_ = self.create_publisher(SteerCommand, 'steer_command', 10)

        self.get_logger().info("User Input Node initialized. Waiting for input...")

    def publish_user_input(self, steer_percentage):
        msg = SteerCommand()
        msg.steer_percentage = steer_percentage
        self.publisher_.publish(msg)
        self.get_logger().info(f"Published steer_pwm: {steer_percentage}")


def main(args=None):
    rclpy.init(args=args)

    user_input_node = UserInputNode()

    try:
        while rclpy.ok():
            # Get user input from stdin
            try:
                steer_percentage = int(input("Enter steer_percentage value (integer): "))

                # Publish the user input as a message
                user_input_node.publish_user_input(steer_percentage)

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
