# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project's name
project(main)

find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED opencv)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --libs opencv")
set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# Add training datas
add_custom_target(training_data ALL 
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/training_data ${EXECUTABLE_OUTPUT_PATH}/training_data
)

# Exécutables
add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(main ${OPENCV_LIBRARIES})
