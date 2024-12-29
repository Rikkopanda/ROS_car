import rclpy
from rclpy.node import Node
from serial_motor_demo_msgs.msg import MotorCommand
from serial_motor_demo_msgs.msg import SteerCommand
from serial_motor_demo_msgs.msg import DriveCommand
from serial_motor_demo_msgs.msg import MotorVels
from serial_motor_demo_msgs.msg import EncoderVals
import time
import math
import serial
from threading import Lock
import inspect

#sharing data with esp32 c++ side?

def log_function_name(func):
    def wrapper(*args, **kwargs):
        print(f"Calling function: {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

def example_function():
    print("Doing something!")

class MotorDriver(Node):

    def __init__(self):
        super().__init__('motor_driver')

        # Setup parameters
        self.declare_parameter('encoder_cpr', value=0)
        if (self.get_parameter('encoder_cpr').value == 0):
            print("WARNING! ENCODER CPR SET TO 0!!")

        self.declare_parameter('loop_rate', value=0)
        if (self.get_parameter('loop_rate').value == 0):
            print("WARNING! LOOP RATE SET TO 0!!")

        self.declare_parameter('serial_port', value="/dev/ttyUSB0")
        self.serial_port = self.get_parameter('serial_port').value

        self.declare_parameter('baud_rate', value=115200)
        self.baud_rate = self.get_parameter('baud_rate').value

        self.declare_parameter('dry_test', False)  # Cycles per second

        self.declare_parameter('serial_debug', value=True)
        self.debug_serial_cmds = self.get_parameter('serial_debug').value
        if (self.debug_serial_cmds):
            print("Serial debug enabled")

        # Setup topics & services

        # self.subscription = self.create_subscription(
        #     MotorCommand,
        #     'motor_command',
        #     self.motor_command_callback,
        #     10)

        self.subscription = self.create_subscription(
            SteerCommand,
            'steer_command',
            self.steer_command_callback,
            10)

        self.subscription = self.create_subscription(
            DriveCommand,
            'drive_command',
            self.drive_command_callback,
            10)

        self.speed_pub = self.create_publisher(MotorVels, 'motor_vels', 10)

        self.encoder_pub = self.create_publisher(EncoderVals, 'encoder_vals', 10)

        # Member Variables

        self.last_enc_read_time = time.time()
        self.last_m1_enc = 0
        self.last_m2_enc = 0
        self.m1_spd = 0.0
        self.m2_spd = 0.0

        self.mutex = Lock()

        # Open serial comms
        if (self.get_parameter('dry_test').value == False):
            print(f"Connecting to port {self.serial_port} at {self.baud_rate}.")
            self.conn = serial.Serial(self.serial_port, self.baud_rate, timeout=1.0)
            print(f"Connected to {self.conn}")
        else:
            print(f"Dry test = True, so no connect attempt")

    # Raw serial commands

    def send_feedback_motor_command(self, mot_1_ct_per_loop, mot_2_ct_per_loop):
        self.send_command(f"m {int(mot_1_ct_per_loop)} {int(mot_2_ct_per_loop)}\n")

    def send_encoder_read_command(self):
        resp = self.send_command(f"e\n")
        if resp:
            return [int(raw_enc) for raw_enc in resp.split()]
        return []

    def steer_command_callback(self, steer_msg):
        print(f"sending steer_percentage; {int(steer_msg.steer_percentage)}")
        self.send_command(f"S{int(steer_msg.steer_percentage)}\n")

    def drive_command_callback(self, drive_msg):
        print(f"drive_command_callback, drive_command; {drive_msg.drive_percentage}")
        self.send_command(f"D{int(drive_msg.drive_percentage)}\n")

    # def motor_command_callback(self, motor_command):
    #     if (motor_command.is_pwm):
    #         self.send_pwm_motor_command(motor_command.mot_1_req_rad_sec, motor_command.mot_2_req_rad_sec)
    #     else:
    #         # counts per loop = req rads/sec X revs/rad X counts/rev X secs/loop 
    #         scaler = (1 / (2*math.pi)) * self.get_parameter('encoder_cpr').value * (1 / self.get_parameter('loop_rate').value)
    #         mot1_ct_per_loop = motor_command.mot_1_req_rad_sec * scaler
    #         mot2_ct_per_loop = motor_command.mot_2_req_rad_sec * scaler
    #         self.send_feedback_motor_command(mot1_ct_per_loop, mot2_ct_per_loop)

    def check_encoders(self):
        resp = self.send_encoder_read_command()
        if (resp):

            new_time = time.time()
            time_diff = new_time - self.last_enc_read_time
            self.last_enc_read_time = new_time

            m1_diff = resp[0] - self.last_m1_enc
            self.last_m1_enc = resp[0]
            m2_diff = resp[1] - self.last_m2_enc
            self.last_m2_enc = resp[1]

            rads_per_ct = 2*math.pi/self.get_parameter('encoder_cpr').value
            self.m1_spd = m1_diff*rads_per_ct/time_diff
            self.m2_spd = m2_diff*rads_per_ct/time_diff

            spd_msg = MotorVels()
            spd_msg.mot_1_rad_sec = self.m1_spd
            spd_msg.mot_2_rad_sec = self.m2_spd
            self.speed_pub.publish(spd_msg)

            enc_msg = EncoderVals()
            enc_msg.mot_1_enc_val = self.last_m1_enc
            enc_msg.mot_2_enc_val = self.last_m2_enc
            self.encoder_pub.publish(enc_msg)

    # Outputs:
    # Calling function: example_function
    # Doing something!

    # Utility functions
    @log_function_name
    def send_command(self, cmd_string):
        # print(f"current func name: {inspect.currentframe().f_code.co_name}")
        if (self.get_parameter('dry_test').value == True):
            print(f"Dry test = True, so no connect attempt")
            return
        self.mutex.acquire()
        try:
            cmd_string += "\r"
            self.conn.write(cmd_string.encode("utf-8"))
            if (self.debug_serial_cmds):
                print("Sent: " + cmd_string)

            # ## Adapted from original
            # c = ''
            # value = ''
            # while c != '\r':
            #     c = self.conn.read(1).decode("utf-8")
            #     if (c == ''):
            #         print("Error: Serial timeout on command: " + cmd_string)
            #         return ''
            #     value += c

            # value = value.strip('\r')

            # if (self.debug_serial_cmds):
            #     print("Received: " + value)
            # return value
        finally:
            self.mutex.release()

    def close_conn(self):
        self.conn.close()



def main(args=None):
    
    rclpy.init(args=args)

    motor_driver = MotorDriver()

    rate = motor_driver.create_rate(2)
    while rclpy.ok():
        rclpy.spin_once(motor_driver)
        # motor_driver.check_encoders()

    motor_driver.close_conn()
    motor_driver.destroy_node()
    rclpy.shutdown()
