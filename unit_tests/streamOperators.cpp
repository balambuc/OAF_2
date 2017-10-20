#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("<< es >> operatorok", "[operator(>>/<<)]") {
    std::stringstream ss[3];

    Bignum i(1234);
    ss[0] << i;

    Bignum in;
    ss[1] << "5678";
    ss[1] >> in;
    ss[2] << in;

    SECTION("<<", "kiiro op")
    {
        CHECK(ss[0].str() == "1234");
    }

    SECTION(">>", "beolvaso op")
    {
        CHECK(ss[2].str() == ss[1].str());
    }
}