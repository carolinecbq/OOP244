cmake_minimum_required(VERSION 4.0)
project(Workshop9)

set(CMAKE_CXX_STANDARD 11)

add_executable(Workshop9 main.cpp
        Marks.h
        Utils.h
        Transcript.cpp
        Transcript.h
        Utils.cpp
        Marks.cpp)
