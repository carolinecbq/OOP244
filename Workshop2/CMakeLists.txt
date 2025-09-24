cmake_minimum_required(VERSION 4.0)
project(Workshop2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Workshop2 main.cpp
        cstr.h
        sensorAnalysis.cpp
        cstr.cpp
        sensorAnalysis.h
        dma.h
        dma.cpp)
