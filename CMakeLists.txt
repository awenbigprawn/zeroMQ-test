# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(HelloProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the paths manually (modify these paths to match your system)
set(ZeroMQ_INCLUDE_DIR /usr/local/include)
set(ZeroMQ_LIBRARY /usr/lib/x86_64-linux-gnu/libzmq.so)

# Add the include directory
include_directories(${ZeroMQ_INCLUDE_DIR})

# Add the executable for the server
add_executable(hello_server hello_server.cpp)

# Add the executable for the client
add_executable(hello_client hello_client.cpp)

# Link the ZeroMQ library to the server and client executables
target_link_libraries(hello_server ${ZeroMQ_LIBRARY})
target_link_libraries(hello_client ${ZeroMQ_LIBRARY})

