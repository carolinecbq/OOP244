cmake_minimum_required(VERSION 4.0)
project(Milestone1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Milestone1 main.cpp
        constants.h
        Menu.cpp
        Menu.h
        Utils.h
        Utils.cpp)
