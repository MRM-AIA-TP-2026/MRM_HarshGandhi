from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory
import os
import xacro

def generate_launch_description():
    pkg_share = get_package_share_directory('mobile_robot')
    robot_description_path = os.path.join(pkg_share, 'model', 'rover.xacro')
    
    # Process XACRO file
    robot_description = xacro.process_file(robot_description_path).toxml()
    
    return LaunchDescription([
        # Launch Gazebo
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so'],
            output='screen'
        ),
        
        # Robot State Publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': robot_description}]
        ),
        
        # Spawn the robot
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'six_wheel_rover',
                '-topic', 'robot_description',  # Removed the leading slash
                '-x', '0', '-y', '0', '-z', '0.5'
            ],
            output='screen'
        ),
        
        # Teleop
        Node(
            package='teleop_twist_keyboard',
            executable='teleop_twist_keyboard',
            name='teleop_twist_keyboard',
            output='screen'
        )
    ])
