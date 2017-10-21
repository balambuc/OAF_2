/**
 * \test {exceptions}
 */

#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Kivetelkezeles", "[exceptions]") {

    Bignum b;
    std::stringstream ss;

    SECTION("negativ", "NotNaturalNum exceptiont kel dobnia")
    {
        Bignum* b;
        CHECK_THROWS_AS(b = new Bignum(-1235), NotNaturalNum&);
    }

    SECTION("nem szam", "NotNaturalNum exceptiont kel dobnia")
    {
        ss.str("12abe");
        CHECK_THROWS_AS(ss >> b, NotNaturalNum&);
    }

    SECTION("0-val kezd", "StartsWithZero exceptiont kel dobnia")
    {
        ss.str("01234");
        CHECK_THROWS_AS(ss >> b, StartsWithZero&);
    }
}

