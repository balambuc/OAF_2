cmake_minimum_required(VERSION 3.2)
project(2bead)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)


add_test(NAME unit_tests COMMAND tests)