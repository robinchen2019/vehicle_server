cmake_minimum_required(VERSION 3.5)
project(vehicle_server)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(BOOST_ROOT "$ENV{BOOST_ROOT}")
set(BOOST_LIBRARYDIR "$ENV{BOOST_ROOT}/lib64-msvc-17.1")
# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(vehicle_server
    src/vehicle_server_node.cpp
    src/vehicleserver.cpp
    src/tcpserver.cpp
)

ament_target_dependencies(vehicle_server rclcpp )
target_link_libraries (vehicle_server ${Boost_LIBRARIES})

install(TARGETS
  vehicle_server
  DESTINATION lib/${PROJECT_NAME})
ament_package()


