add_library(src STATIC
        headers/BigNum
        BigNum.cpp
        )

target_include_directories(src PUBLIC headers)
