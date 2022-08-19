cmake_minimum_required(VERSION 2.8.3)
project(test_pkg)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
set(CMAKE_CXX_STANDARD 14)

add_message_files(DIRECTORY msg FILES 
    aabbccddeeffgghhiij.msg
    aabbccddeeffgghhii.msg
    )

generate_messages(DEPENDENCIES std_msgs)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(test_app src/main.cpp)
target_link_libraries(test_app ${catkin_LIBRARIES})
