


# testing how to use

ros2 run serial_motor_demo driver --ros-args -p dry_test:=True 


ros2 run serial_motor_demo basic_control --ros-args -p steering_amplitude:=11 -p steer_speed:=1 -p steering_frequency:=0.015 -p drive_speed:=7


run in background add & 

ros2 run <package_name> <node_name> > stdout.log 2> stderr.log &


sudo apt install moreutils

ros2 run <package_name> <node_name> | ts '[%Y-%m-%d %H:%M:%S]' > stdout.log 2> >(ts '[%Y-%m-%d %H:%M:%S]' > stderr.log) &
