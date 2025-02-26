# ROS2 Joy Web Interface Deployment

This repository provides a simple Makefile to deploy a web-based ROS2 joystick interface with three services, each launched in a new terminal window:

1. **rosbridge server:** Exposes ROS topics over WebSockets.
2. **joy node:** Reads a joystick on `/dev/input/js0` and publishes to `/joy`.
3. **HTTP server:** Serves your web page (which uses `roslib.js`) via a simple Python HTTP server.

## Prerequisites

- **ROS2 Humble** (or your chosen ROS2 distribution) must be installed.
- The `joy` and `rosbridge_server` packages should be installed.
- A terminal emulator that supports launching new windows via command-line (e.g., `gnome-terminal`).
- Python 3 installed.

## Files

- **Makefile:** Contains commands to launch all services, each in its own terminal.
- **README.md:** This file.
- **index.html:** Your web page that uses `roslib.js` to subscribe to `/joy`.

## How to Deploy

1. **Set Up Your Environment:**
   Open a terminal and source your ROS2 environment:
   ```bash
   source /opt/ros/$(ROS_DISTRO)/setup.bash

