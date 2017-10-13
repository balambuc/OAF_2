cmake_minimum_required(VERSION 3.2)
project(tests)

set(CMAKE_CXX_STANDARD 11)

add_executable(tests
        catch.hpp
        operator+.cpp
        ctor.cpp
        main.cpp
        streamOperators.cpp)

target_link_libraries(tests src)

