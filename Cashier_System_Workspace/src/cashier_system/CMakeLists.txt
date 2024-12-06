cmake_minimum_required(VERSION 3.8)
project(cashier_system)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate custom message
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Bill.msg"
  DEPENDENCIES builtin_interfaces
)

# Bill Publisher Executable
add_executable(bill_publisher_node src/bill_publisher_node.cpp)
ament_target_dependencies(bill_publisher_node 
  rclcpp 
  std_msgs
)
rosidl_target_interfaces(bill_publisher_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Bill Listener Executable
add_executable(bill_listener_node src/bill_listener_node.cpp)
ament_target_dependencies(bill_listener_node 
  rclcpp 
  std_msgs
)
rosidl_target_interfaces(bill_listener_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Cashier Executable
add_executable(cashier_node src/cashier_node.cpp)
ament_target_dependencies(cashier_node 
  rclcpp 
  std_msgs
)
rosidl_target_interfaces(cashier_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Install targets
install(TARGETS
  bill_publisher_node
  bill_listener_node
  cashier_node
  DESTINATION lib/${PROJECT_NAME}
)

# Required for ament
ament_package()
