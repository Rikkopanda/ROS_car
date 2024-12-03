import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/rikverhoeven/Documents/mechatronic_projects/ROS_auto_robot/ros2_ws_02/install/test_package_02'
