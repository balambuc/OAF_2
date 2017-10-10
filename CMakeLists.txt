cmake_minimum_required(VERSION 3.8)
project(2bead)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BigNum.cpp BigNum.h)
add_executable(2bead ${SOURCE_FILES})