cmake_minimum_required(VERSION 3.27)
project(Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MACOSX_RPATH ON)

add_library(Library SHARED library.cpp)
