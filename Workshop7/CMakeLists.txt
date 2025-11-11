cmake_minimum_required(VERSION 4.0)
project(Workshop7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Workshop7
        Employee.cpp
        Employee.h
        main.cpp
        Professor.cpp
        Professor.h
        Utils.cpp
        Utils.h)
