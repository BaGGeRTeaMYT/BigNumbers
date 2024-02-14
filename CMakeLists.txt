cmake_minimum_required(VERSION 3.20)
project(Homework)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(big SHARED ${SOURCES})
target_include_directories(big PUBLIC headers)

add_executable(main main.cpp)
target_link_libraries(main big)