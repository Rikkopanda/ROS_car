import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/rikverhoeven/Documents/mechatronic_projects/ROS_auto_robot/control_robot_test/serial_motor_demo_ws/src/serial_motor_demo/install/serial_motor_demo'
