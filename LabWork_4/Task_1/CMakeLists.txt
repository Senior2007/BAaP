cmake_minimum_required(VERSION 3.27)
project(Task_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_1 main.cpp
        HeapSort.cpp
        HeapSort.h
        QuickSort.cpp
        QuickSort.h
        MergeSort.cpp
        MergeSort.h)
