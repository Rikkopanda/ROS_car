



ros2 run rosbridge_server rosbridge_websocket


# running web server serving html page
python3 -m http.server 8000


ros2 run joy joy_node --ros-args -p autorepeat_rate:=5.0

# opens websocket with ros node 
ros2 launch rosbridge_server rosbridge_websocket_launch.xml
allows for web browser to interact with ros nodes. It is a ros node, with a websocket open.

browser makes connection with websocket, aka a subsciption. these actions from browser are defined in roslib.js

## uses roslib on webserver side; 
git repo used; -branch ros2
https://github.com/RobotWebTools/roslibjs/blob/ros2/build/roslib.js


