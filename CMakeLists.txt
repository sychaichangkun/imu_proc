cmake_minimum_required(VERSION 2.8.3)
project(imu_proc)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
  std_msgs
  xbot_msgs
)
catkin_package(
    INCLUDE_DIRS include include/imu_proc
    LIBRARIES MadgwickAHRS MahonyAHRS
    CATKIN_DEPENDS   roscpp rospy std_msgs
    )

include_directories(
    include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(
    MadgwickAHRS
  include/imu_proc/MadgwickAHRS.cpp
)

add_library(
  MahonyAHRS
  include/imu_proc/MahonyAHRS.cpp
)

add_executable(imu_proc src/imu_proc.cpp)
target_link_libraries(imu_proc ${catkin_LIBRARIES} MadgwickAHRS MahonyAHRS)

