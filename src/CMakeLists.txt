add_library(src STATIC
        headers/Bignum.h
        headers/Bignum_exceptions.h
        Bignum.cpp
        multiply.cpp
        )

target_include_directories(src PUBLIC headers)
