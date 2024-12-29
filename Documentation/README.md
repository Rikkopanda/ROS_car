


# testing how to use

ros2 run serial_motor_demo driver --ros-args -p dry_test:=True 


ros2 run serial_motor_demo basic_control --ros-args -p steering_amplitude:=11 -p steer_speed:=1 -p steering_frequency:=0.015 -p drive_speed:=7


run in background add & 

ros2 run <package_name> <node_name> > stdout.log 2> stderr.log &


sudo apt install moreutils

ros2 run <package_name> <node_name> | ts '[%Y-%m-%d %H:%M:%S]' > stdout.log 2> >(ts '[%Y-%m-%d %H:%M:%S]' > stderr.log) &




# side notes
https://husarion.com/tutorials/ros2-tutorials/6-robot-network/
for lan wifi communication;

export ROS_LOCALHOST_ONLY=0

set ROS_DOMAIN_ID to same on both machines

export ROS_DOMAIN_ID=5 for example
echo "export ROS_DOMAIN_ID=201" >> ~/.bashrc

