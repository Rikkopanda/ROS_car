import rclpy
from rclpy.node import Node
import math
import time

from serial_motor_demo_msgs.msg import SteerCommand
from serial_motor_demo_msgs.msg import MotorCommand

class RCCarController(Node):
    def __init__(self):
        super().__init__('rc_car_controller')

        # Publishers for steering and motor commands
        self.steer_pub = self.create_publisher(SteerCommand, 'steer_command', 10)
        self.drive_pub = self.create_publisher(MotorCommand, 'motor_command', 10)

        # Subscription for manual override commands
        self.manual_steer_sub = self.create_subscription(
            SteerCommand,
            'manual_steer_command',
            self.manual_steer_callback,
            10)
        
        self.manual_drive_sub = self.create_subscription(
            MotorCommand,
            'manual_motor_command',
            self.manual_drive_callback,
            10)

        # Parameters for steering motion
        self.declare_parameter('steering_amplitude', 10)  # PWM range for steering
        self.declare_parameter('steering_frequency', 0.5)  # Cycles per second
        self.declare_parameter('drive_speed', 5)  # PWM or rad/s for driving
        self.declare_parameter('steer_speed', 1)  # PWM or rad/s for driving

        print("hello")
        
        # State variables
        self.manual_mode = False
        self.manual_steer_value = 0
        self.manual_drive_value = 0

        # Create a timer for autonomous steering
        self.timer = self.create_timer(self.get_parameter('steer_speed').value, self.autonomous_control)

    def autonomous_control(self):
        # Skip if in manual mode
        if self.manual_mode:
            return

        # Get parameters
        amplitude = self.get_parameter('steering_amplitude').value
        frequency = self.get_parameter('steering_frequency').value
        # drive_speed = self.get_parameter('drive_speed').value

        # Calculate time-based steering
        current_time = time.time()
        steering_value = (amplitude * math.sin(2 * math.pi * frequency * current_time)) + 40

        # Publish steering command
        steer_msg = SteerCommand()
        steer_msg.steer_percentage = steering_value
        self.steer_pub.publish(steer_msg)

        # Publish constant drive command
        # drive_msg = MotorCommand()
        # drive_msg.is_pwm = True  # Assuming PWM mode
        # drive_msg.mot_2_req_rad_sec = drive_speed
        # self.drive_pub.publish(drive_msg)

    def manual_steer_callback(self, msg):
        # Enter manual mode and store manual steering value
        self.manual_mode = True
        self.manual_steer_value = msg.steer_percentage

        # Publish manual steering command
        steer_msg = SteerCommand()
        steer_msg.steer_percentage = self.manual_steer_value
        self.steer_pub.publish(steer_msg)

    def manual_drive_callback(self, msg):
        # Enter manual mode and store manual drive value
        self.manual_mode = True
        self.manual_drive_value = msg.mot_2_req_rad_sec

        # Publish manual drive command
        # drive_msg = MotorCommand()
        # drive_msg.is_pwm = msg.is_pwm
        # drive_msg.mot_2_req_rad_sec = self.manual_drive_value
        # self.drive_pub.publish(drive_msg)

def main(args=None):
    rclpy.init(args=args)
    rc_car_controller = RCCarController()

    rclpy.spin(rc_car_controller)

    rc_car_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()