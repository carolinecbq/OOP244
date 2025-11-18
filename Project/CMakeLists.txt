cmake_minimum_required(VERSION 4.0)
project(Milestone1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Milestone1
        constants.h
        Menu.cpp
        Menu.h
        Utils.h
        Utils.cpp
        ms3.cpp
        Drink.cpp
        Drink.h
        Food.cpp
        Food.h
        Billable.cpp
        Billable.h)
