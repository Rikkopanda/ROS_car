import rclpy
from rclpy.node import Node
from serial_motor_msgs.msg import MotorCommand
from serial_motor_msgs.msg import MotorVels
from serial_motor_msgs.msg import EncoderVals
from serial_motor_msgs.msg import SerialLog
from serial_motor_msgs.msg import CustomRequest
import time
import math
import serial
from threading import Lock
from std_msgs.msg import String
from rclpy.qos import QoSProfile, QoSReliabilityPolicy

class MotorDriver(Node):

	def __init__(self):
		super().__init__('motor_driver')
		qos_profile = QoSProfile(depth=100, reliability=QoSReliabilityPolicy.RELIABLE)

		self.declare_parameter('serial_port', value="/dev/ttyUSB0")
		self.serial_port = self.get_parameter('serial_port').value

		self.declare_parameter('baud_rate', value=57600)
		self.baud_rate = self.get_parameter('baud_rate').value

		# Setup topics & services
		self.subscription = self.create_subscription(
			MotorCommand,
			'motor_command',
			self.motor_command_callback,
			10)
		self.custom_request_sub = self.create_subscription(
			CustomRequest,
			'custom_request',
			self.custom_request_callback,
			10)
		# self.speed_pub = self.create_publisher(MotorVels, 'motor_vels', 10)
		# self.encoder_pub = self.create_publisher(EncoderVals, 'encoder_vals', 10)
		# self.settings_display = self.create_publisher(MotorVels, 'settings_display', 10)
	
		self.serial_log_pub = self.create_publisher(SerialLog, 'serial_log', qos_profile)
		# Open serial comms
		print(f"Connecting to port {self.serial_port} at {self.baud_rate}.")

		self.conn = serial.Serial(self.serial_port, self.baud_rate, timeout=1.0)
		print(f"Connected to {self.conn}")
		self.timer = self.create_timer(1, self.timer_callback)

	# Raw serial commands
	def send_pwm_motor_command(self, mot_1_pwm, mot_2_pwm):
		self.send_command(f"o {int(mot_1_pwm)} {int(mot_2_pwm)}")

	def motor_command_callback(self, motor_command):
		if (motor_command.is_pwm):
			self.send_pwm_motor_command(motor_command.mot_1_req_rad_sec, motor_command.mot_2_req_rad_sec)
	# Utility functions

	def custom_request_callback(self, custom_request):
		if (custom_request.str == "p"):
			self.send_command("p")
		print("custom request")
		print(custom_request.str)

	def timer_callback(self):
		if self.conn.in_waiting:
			msg = SerialLog()
			try:
				line = self.conn.readline().decode('utf-8').rstrip()
			except UnicodeDecodeError:
				line = "UniDecodeError"
			except:
				line = "Some unknown error"
			msg.serial_msg = line
			self.serial_log_pub.publish(msg)
			# print(f"msg: ", msg.data)

	def read_command(self, cmd_string):
		c = ''
		value = ''
		while c != '\r' & c != '\n':
			c = self.conn.read(1).decode("utf-8")
			if (c == ''):
				print("Error: Serial timeout on command: " + cmd_string)
				return ''
			value += c
		value = value.strip('\r')
		value = value.strip('\n')
		print("Received: " + value)
		return value
	
	def send_command(self, cmd_string):
		self.conn.write(cmd_string.encode("utf-8"))
		print("Sent: " + cmd_string)
		# return self.read_command(cmd_string)

def main(args=None):
	rclpy.init(args=args)

	motor_driver = MotorDriver()
	
	rclpy.spin(motor_driver)

	motor_driver.close_conn()
	motor_driver.destroy_node()
	rclpy.shutdown()
