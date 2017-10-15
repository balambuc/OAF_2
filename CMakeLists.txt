cmake_minimum_required(VERSION 3.2)
project(2bead)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS="-g -O0 -Wall -W -Wshadow -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

if(TRAVIS)
    message(Currently building with Travis CI)
    if(CMAKE_COMPILER_IS_GNUCXX)
        include(CodeCoverage)
        setup_target_for_coverage(${PROJECT_NAME}_coverage tests coverage)
    endif()

    if(NOT CMAKE_VERSION VERSION_LESS 3.1)
        set(CMAKE_CXX_STANDARD 11)
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")

endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)

add_test(NAME unit_tests COMMAND tests)