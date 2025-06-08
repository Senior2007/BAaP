cmake_minimum_required(VERSION 3.27)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Task_2 main.cpp
        /Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_5/Library/library.cpp
)

target_include_directories(Task_2 PRIVATE
        /Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_5/Library
)