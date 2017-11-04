cmake_minimum_required(VERSION 3.2)
project(2bead)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weffc++ -g -O0 -coverage")

enable_testing()

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(unit_tests)

