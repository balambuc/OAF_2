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
        "operator(mul).cpp"
        )

target_link_libraries(tests src)

add_test(NAME ctors COMMAND ctor)
add_test(NAME streamOp COMMAND streamOperators)
add_test(NAME copyAssign COMMAND cpyCtor_op=)
add_test(NAME op+ COMMAND operator+)
add_test(NAME op* COMMAND "operator(mul)")


