#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "BigNum.h"

TEST_CASE("Ket nagyszam osszeadasa", "[op+]")
{
    std::stringstream ss;

    SECTION("0 elem vizsgalata")
    {
        ss << BigNum(1234) + BigNum(0); //"1234"
        CHECK(ss.str() == "1234");
    }
}