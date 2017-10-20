#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Copy konstruktor es ertekadas operator", "[Bignum(Bignum) op=]") {
    std::stringstream ss[2];

    Bignum a(1234);     // a = 1234
    Bignum b(a);        // b = 1234 (copy)
    ss[0] << "456";     // ss0 = 456
    ss[0] >> a;         // a = 456
    ss[1] << b;         // ss1 = 1234

    SECTION("copy ctor", "Copy konstruktor tesztelese")
    {
        CHECK(ss[1].str() == "1234");
    }

    b = a;              // b = 456
    ss[0] << "7";       // ss0 = 4567
    ss[0] >> a;         // a = 4567
    ss[1] << b;         // ss1 = 1234456

    SECTION("op=", "Ertekadas operator tesztelese")
    {
        CHECK(ss[1].str() == "1234456");
    }
}