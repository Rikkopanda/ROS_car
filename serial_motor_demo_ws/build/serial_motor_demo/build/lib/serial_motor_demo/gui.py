import rclpy
from rclpy.node import Node
import time
from tkinter import *
import math

from serial_motor_msgs.msg import MotorCommand
from serial_motor_msgs.msg import MotorVels
from serial_motor_msgs.msg import EncoderVals


class MotorGui(Node):

	def __init__(self):
		super().__init__('motor_gui')
		self.publisher = self.create_publisher(MotorCommand, 'motor_command', 10)
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

		mode_frame = Frame(root)
		mode_frame.pack(fill=X)
		self.mode_btn = Button(mode_frame, text="Switch PWM msg mode", command=self.switch_mode)
		self.mode_btn.pack(expand=True)

		motor_btns_frame = Frame(root)
		motor_btns_frame.pack()
		Button(motor_btns_frame, text='Send Once', command=self.send_motor_once).pack(side=LEFT)
		Button(motor_btns_frame, text='Send Cont.', command=self.show_values).pack(side=LEFT)

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

	def set_mode(self, new_mode):
		self.pwm_mode = new_mode

	def switch_mode(self):
		self.set_mode(not self.pwm_mode)



def main(args=None):
	rclpy.init(args=args)

	motor_gui = MotorGui()
	
	rate = motor_gui.create_rate(20)
	motor_gui.tk.mainloop()
	while rclpy.ok():
		rclpy.spin_once(motor_gui)
		# motor_gui.update()
	motor_gui.destroy_node()
	rclpy.shutdown()