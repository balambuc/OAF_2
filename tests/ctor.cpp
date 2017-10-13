#include "catch.hpp"
#include "BigNum.h"

TEST_CASE("Nagyszam osztaly konstruktorai", "BigNum(int/str)") {
    std::stringstream ss[2];

    BigNum i(1234);
    ss[0] << i;

    BigNum s("1234");
    ss[1] << s;

    SECTION("int")
    {
        CHECK(ss[0].str() == "1234");
    }

    SECTION("str")
    {

        CHECK(ss[1].str() == "1234");
    }

    SECTION("int == str")
    {
        CHECK(ss[0].str() == ss[1].str());
    }
}