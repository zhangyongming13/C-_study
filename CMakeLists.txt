cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Cmake test.cpp)