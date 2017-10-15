cmake_minimum_required(VERSION 3.2)
project(2bead)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

enable_testing()

find_package(codecov)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)

add_test(NAME unit_tests COMMAND tests)

coverage_evaluate()