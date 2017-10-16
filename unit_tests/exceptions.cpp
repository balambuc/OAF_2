#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Kivetelkezeles", "[exceptions]") {

    Bignum b;
    std::stringstream ss;

    SECTION("negativ")
    {
        ss.str("-123");
        CHECK_THROWS_AS(ss >> b, NotNaturalNum&);
    }


    SECTION("nem szam")
    {
        ss.str("12abe");
        CHECK_THROWS_AS(ss >> b, NotNaturalNum&);
    }

    SECTION("0-val kezd")
    {
        ss.str("01234");
        CHECK_THROWS_AS(ss >> b, StartsWithZero&);
    }
}

