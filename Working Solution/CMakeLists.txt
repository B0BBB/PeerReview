cmake_minimum_required(VERSION 3.9)
project(Robot1)

set(CMAKE_CXX_STANDARD 98)

add_executable(Robot1 main.cpp Interface.cpp Map.cpp RobotDB.cpp Robot.cpp)