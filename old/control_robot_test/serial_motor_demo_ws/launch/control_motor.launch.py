from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='serial_motor_demo',
            namespace='test_space_01',
            executable='gui',
            name='gui'
        ),
        Node(
            package='serial_motor_demo',
            namespace='test_space_01',
            executable='driver',
            name='driver'
        )
    ])
