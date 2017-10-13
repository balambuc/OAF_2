#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "BigNum.h"

TEST_CASE("Ket nagyszam osszeadasa", "BigNum")
{
    std::stringstream ss[3];

    SECTION("0 elem vizsgalata")
    {
        ss[0] << BigNum(1234) + BigNum(0); //"1234"
        CHECK(ss[0].str() == "1234");
    }

    SECTION("kommutativitas vizsgalata")
    {
        ss[0] << BigNum(1234) + BigNum(5678);
        ss[1] << BigNum(5678) + BigNum(1234);
        CHECK(ss[0].str() == ss[1].str());
    }
}