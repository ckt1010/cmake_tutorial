cmake_minimum_required(VERSION 3.10)

project(step1 VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(step1.h.in step1.h)
add_executable(step1 step1.cpp)
target_include_directories(step1 PUBLIC "${PROJECT_BINARY_DIR}")