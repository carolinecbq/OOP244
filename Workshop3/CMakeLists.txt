cmake_minimum_required(VERSION 4.0)
project(Workshop3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Workshop3
        CC.cpp
        CC.h
        cstr.cpp
        cstr.h
        main.cpp
        cc.csv)
