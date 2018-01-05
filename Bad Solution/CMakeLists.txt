cmake_minimum_required(VERSION 3.9)
project(Workingsol)

set(CMAKE_CXX_STANDARD 14)

add_executable(Workingsol main.cpp Interface.cpp Map.cpp MoveRobot.cpp RobotDB.cpp)