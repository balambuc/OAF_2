cmake_minimum_required(VERSION 3.2)
project(tests)

set(CMAKE_CXX_STANDARD 11)

add_executable(tests
        catch.hpp
        main.cpp
        ctor.cpp
        streamOperators.cpp
        cpyCtor_op=.cpp
        operator+.cpp
        )

target_link_libraries(tests src)

