cmake_minimum_required(VERSION 3.20)
project(BigNum)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_library(MyLib STATIC headers/big.h)
# target_link_libraries(BigNum PUBLIC headers)
# target_include_directories(MyLib PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

add_executable(BigNum src/main.cpp)