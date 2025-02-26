

SSH_USER = pi

ROS_DOMAIN = 201

WLP3S0_IP := $(shell ip addr show wlp3s0 | grep -m1 'inet ' | awk '{print $$2}')

PI_IP := $(shell nmap -sn ${WLP3S0_IP} | grep -v ".100" | grep -v "_gateway" | grep report | sed -n '1p' | awk '{print $$NF}')

MAKEFILE_DIR := $(shell pwd)

# ANSI color codes
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
BLUE   := \033[34m
CYAN   := \033[36m
RESET  := \033[0m

ROS2_LAUNCH_DIR := ~/Documents/mechatronica_gits/ROS_car/host_ros_control
LAUNCH_CMD := ros2 launch gui_package gui_launch.py

show_ip:
	@echo $(WLP3S0_IP)

show_pi:
	@echo $(PI_IP)

scan:
	@echo "$(GREEN)scanning with nmap -sn;$(RESET)"
	nmap -sn $(WLP3S0_IP)

# all: car_startup laptop_gamer_control

laptop_gamer_control:
	unset GTK_PATH 
	@gnome-terminal -- bash -c "env | grep ROS_DO && cd $(ROS2_LAUNCH_DIR) && source install/setup.sh && ros2 run joy joy_node; exec bash"
	@gnome-terminal -- bash -c "env | grep ROS_DO && sleep 1 && cd $(ROS2_LAUNCH_DIR) && source install/setup.sh && ros2 run serial_motor_demo game_controller_control; exec bash"

car_startup:
	@echo "Starting ROS2 nodes on the RC car..."
	unset GTK_PATH
	@gnome-terminal -- bash -c "sshpass -p 'hoi1hoi1' ssh -t $(SSH_USER)@$(PI_IP) 'hostname -I && whoami && cd projects/ROS_car/host_ros_control && env | grep ROS && source ~/.bashrc && export ROS_DOMAIN_ID=201 && env | grep ROS && source install/setup.sh && sleep 4 && ps && ros2 run serial_motor_demo driver'; exec bash"

# sshpass -p "hoi1hoi1" ssh $(SSH_USER)@$(PI_IP) "hostname -I && whoami && cd projects/ROS_car/host_ros_control && source install/setup.sh && sleep 4 && ps && ros2 run serial_motor_demo driver"

	@echo "ssh command ended"

car_ssh:
	@echo "Starting ROS2 nodes on the RC car..."
	unset GTK_PATH

	gnome-terminal -- bash -c "sshpass -p 'hoi1hoi1' ssh $(SSH_USER)@$(PI_IP); exec bash"

	@echo "ssh command ended"

#"export ROS_DOMAIN_ID=$(ROS_DOMAIN_ID) && cd projects/ROS_car/host_ros_control && source install/setup.sh && ros2 run serial_motor_control driver"
