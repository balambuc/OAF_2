cmake_minimum_required(VERSION 3.2)
project(2bead)

set(CMAKE_CXX_STANDARD 11) # C++11 standard

## Common flags
# Wall: verbose warning
# Weffc++: warnings based on Scott Meyers Effective c++
# g: make binary more debuggable
# O0: disable optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weffc++ -g -O2")

if ($ENV{TRAVIS}) # On Travis-CI add coverage ability
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
    set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
endif ()

enable_testing()

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(unit_tests)

