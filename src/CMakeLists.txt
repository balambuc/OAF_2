add_library(src STATIC
        headers/Bignum.h
        Bignum.cpp
        multiply.cpp)

target_include_directories(src PUBLIC headers)

