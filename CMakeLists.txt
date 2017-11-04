cmake_minimum_required(VERSION 3.2)
project(2bead)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weffc++ -g -O0 -coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

if ($ENV{TRAVIS})
    message("-------------Building in TRAVIS-CI--------------------")
else ()
    message("-----------Not on TRAVIS----------------")
endif ()

enable_testing()

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(unit_tests)

