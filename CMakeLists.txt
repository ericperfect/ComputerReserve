cmake_minimum_required(VERSION 3.16)
project(ComputerReserve)

set(CMAKE_CXX_STANDARD 14)

add_library(ComputerReserve Identity.h Student.cpp Student.h Teacher.cpp Teacher.h Manager.cpp Manager.h GlobalFile.h ComputerRoom.h OrderFile.cpp OrderFile.h)
add_subdirectory(examples)