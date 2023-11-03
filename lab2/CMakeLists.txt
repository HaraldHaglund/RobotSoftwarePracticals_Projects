# Declare the version of the CMake API for forward-compatibility
cmake_minimum_required(VERSION 2.8)
# Declare the name of the CMake Project
project(lab2_program)
# Add the directory to search for header files
include_directories(include)
# Define an executable target called halfway_checkpoint
add_executable(halfway_checkpoint halfway_checkpoint.cpp)
#Add libraries
add_library(Robot Robot.cpp)
add_library(robot_logic robot_logic.cpp)
add_library(FieldPrinter FieldPrinter.cpp)
#Add the other executables
add_executable(init_robots init_robots.cpp)#Robot.cpp) 
add_executable(init_robots_with_grid init_robots_with_grid.cpp)
add_executable(game_static_robots game_static_robots.cpp)
add_executable(game game.cpp)
#Link libraries
target_link_libraries(FieldPrinter Robot)
target_link_libraries(robot_logic Robot)
target_link_libraries(init_robots Robot robot_logic)
target_link_libraries(init_robots_with_grid robot_logic FieldPrinter Robot)
target_link_libraries(game_static_robots robot_logic FieldPrinter Robot)
target_link_libraries(game robot_logic FieldPrinter Robot)


#file(GLOB SOURCES
#"*.cpp")


#add_executable(game ${SOURCES})


