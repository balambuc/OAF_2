#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Copy konstruktor es ertekadas operator", "[Bignum(Bignum) op=]") {
    std::stringstream ss;

    Bignum a(1234);
    Bignum b(a);
    ss << b;

    SECTION("copy ctor")
    {
        CHECK(ss.str() == "1234");
    }

    SECTION("op=")
    {

        CHECK(ss.str() == "1234");
    }
}