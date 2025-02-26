

# install dingen
controller;
If you're struggling to connect the controller wirelessly try this: Press the share button (left of the touchpad) and the home button together for 3 seconds. The controller should now go into pairing mode and you should be able to find it with bluetooth.
bluetoothctl;
scan on
connect B2:70:23:05:06:07
trust B2:70:23:05:06:07
info B2:70:23:05:06:07
geen /dev/input/js0??

# testen game die controller gebruikt en audio
Word War vi - game

ogg vorbis = audio en music format - libvorbis
depend: libasound2-dev:
maakt gebruik van Advanced Linux Sound Architecture library


portaudio




# handig was bij bouwen
sudo ldconfig -p | grep vorbis
check directories in cache van dynamic linker



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

# extra sources
https://github.com/ArturSpirin/pyPS4Controller
https://salamwaddah.com/blog/connecting-ps4-controller-to-raspberry-pi-via-bluetooth
https://elixirforum.com/t/trying-to-use-joystick-cant-see-access-dev-input-js0-on-rpi3/41979
https://www.baeldung.com/linux/bluetooth-via-terminal
