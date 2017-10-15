add_library(src STATIC
        headers/BigNum
        Bignum.cpp
        )

target_include_directories(src PUBLIC headers)
