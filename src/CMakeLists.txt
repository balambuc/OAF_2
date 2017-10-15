add_library(src STATIC
        headers/Bignum.h
        Bignum.cpp
        )

target_include_directories(src PUBLIC headers)
