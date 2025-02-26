# Variables (adjust these if necessary)
ROS_DISTRO ?= humble
WS_PORT ?= 9090
HTTP_PORT ?= 8000

ROSBRIDGE_WS_DIR ?= ${PWD}/ros2_test_ws

# Terminal command - using gnome-terminal; replace with your terminal if different.
TERMINAL := gnome-terminal -- bash -c

SYM ?= $

.PHONY: all rosbridge joy web stop clean

all: rosbridge joy web


rosbridge:
	@echo "Launching rosbridge server in new terminal..."
	gnome-terminal --title="rosbridge" -- bash -c "source /opt/ros/$(ROS_DISTRO)/setup.bash && source ${ROSBRIDGE_WS_DIR} && ros2 launch rosbridge_server rosbridge_websocket_launch.xml; exec bash"

joy:
	@echo "Launching joy node in new terminal..."
	gnome-terminal --title="joy" -- bash -c "source /opt/ros/$(ROS_DISTRO)/setup.bash && ros2 run joy joy_node --ros-args -p rate:=1 -p dev:=/dev/input/js0; exec bash"

web:
	@echo "Launching HTTP server in new terminal..."
	gnome-terminal --title="web" -- bash -c "cd ${PWD} && echo  ${SYM}PWD && sleep 1 && python3 -m http.server $(HTTP_PORT); exec bash"

stop:
	@echo "Stopping all services..."
	wmctrl -c "rosbridge"
	wmctrl -c "joy"
	wmctrl -c "web"

clean: stop
	@echo "Clean complete."

