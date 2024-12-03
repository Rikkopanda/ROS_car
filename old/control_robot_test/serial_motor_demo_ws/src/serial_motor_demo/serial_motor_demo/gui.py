import rclpy
from rclpy.node import Node
import time
from tkinter import *
from tkinter import ttk
from tkinter.scrolledtext import ScrolledText

import math
from serial_motor_msgs.msg import MotorCommand
from serial_motor_msgs.msg import MotorVels
from serial_motor_msgs.msg import EncoderVals
from serial_motor_msgs.msg import CustomRequest
from serial_motor_msgs.msg import SerialLog
from rclpy.qos import QoSProfile, QoSReliabilityPolicy
from std_msgs.msg import String


class MotorGui(Node):

	def __init__(self):
		super().__init__('motor_gui')
		self.publisher = self.create_publisher(MotorCommand, 'motor_command', 10)
		self.custom_request_publisher = self.create_publisher(CustomRequest, 'custom_request', 10)
		qos_profile = QoSProfile(depth=100, reliability=QoSReliabilityPolicy.RELIABLE)

		self.serial_log_sub = self.create_subscription(
			SerialLog,
			'serial_log',
			self.serial_log_callback,
			qos_profile)

		self.tk = Tk()
		root = Frame(self.tk)
		root.pack(fill=BOTH, expand=True)
		Label(root, text="Serial Motor GUI").pack()

		m1_frame = Frame(root)
		m1_frame.pack(fill=X)
		Label(m1_frame, text="Motor 1").pack(side=LEFT)
		self.m1 = Scale(m1_frame, from_=-255, to=255, orient=HORIZONTAL)
		self.m1.pack(side=LEFT, fill=X, expand=True)

		m2_frame = Frame(root)
		m2_frame.pack(fill=X)
		Label(m2_frame, text="Motor 2").pack(side=LEFT)
		self.m2 = Scale(m2_frame, from_=-255, to=255, resolution=1, orient=HORIZONTAL)
		self.m2.pack(side=LEFT, fill=X, expand=True)

		self.serial_log_frame = Frame(root)
		self.serial_log_frame.pack(fill=X)
		self.serial_label1 = Label(self.serial_log_frame, text="Serial log:").pack(side=LEFT)
		self.serial_label2 = Label(self.serial_log_frame, text="------------")

		self.serial_log_text = ScrolledText(self.serial_log_frame, wrap=WORD, height=3)
		self.serial_log_text.pack(fill=BOTH, expand=True)
		self.serial_log_text.configure(state=DISABLED)
		self.serial_label2.pack(side=LEFT)

		mode_frame = Frame(root)
		mode_frame.pack(fill=X)
		self.mode_btn = Button(mode_frame, text="Switch PWM msg mode", command=self.switch_mode)
		self.mode_btn.pack(expand=True)

		motor_btns_frame = Frame(root)
		motor_btns_frame.pack()
		Button(motor_btns_frame, text='Send Once', command=self.send_motor_once).pack(side=LEFT)
		Button(motor_btns_frame, text='Send Cont.', command=self.show_values).pack(side=LEFT)
		Button(motor_btns_frame, text='Ping', command=self.ping).pack(side=LEFT)
		# Button(motor_btns_frame, text='Test log function', command=self.serial_log_callback()).pack(side=LEFT)
		self.set_mode(True) # sets isPWM mode


	def send_motor_once(self):
		msg = MotorCommand()
		msg.is_pwm = self.pwm_mode
		if (self.pwm_mode):
			msg.mot_1_req_rad_sec = float(self.m1.get())
			msg.mot_2_req_rad_sec = float(self.m2.get())
		self.publisher.publish(msg)

	def show_values(self):
		print (self.m1.get(), self.m2.get())

	def ping(self):
		msg = CustomRequest()
		msg.str = "p"
		self.custom_request_publisher.publish(msg)
		print("send ping")

	def set_mode(self, new_mode):
		self.pwm_mode = new_mode

	def switch_mode(self):
		self.set_mode(not self.pwm_mode)

	def serial_log_callback(self, serial_log):
		self.tk.after(0, self.update_log_text, serial_log.serial_msg)
		print("msg in gui: ", serial_log.serial_msg)

	def update_log_text(self, new_text):
		self.serial_log_text.configure(state=NORMAL)
		self.serial_log_text.insert(END, new_text + '\n')
		self.serial_log_text.see(END)
		self.serial_log_text.configure(state=DISABLED)

	def update_label(self, new_text):
		self.serial_label2.config(text=new_text)

	def update(self):
		self.tk.update()
	def ros_spin(self):
		rclpy.spin_once(self, timeout_sec=0.1)
		self.tk.after(100, self.ros_spin)

def main(args=None):
	rclpy.init(args=args)

	motor_gui = MotorGui()
	
	rate = motor_gui.create_rate(20)

	# while rclpy.ok():
	# 	rclpy.spin_once(motor_gui)
	# 	motor_gui.update()
	motor_gui.tk.after(100, motor_gui.ros_spin)
	motor_gui.tk.mainloop()
	
	motor_gui.destroy_node()
	rclpy.shutdown()