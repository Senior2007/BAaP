cmake_minimum_required(VERSION 3.27)
project(Task_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_3 main.cpp
        Expression.cpp
        Expression.h
        Number.cpp
        Number.h
        BinaryOperation.cpp
        BinaryOperation.h)
