/**
 * \test {constructors}
 */

#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Nagyszam osztaly konstruktorai", "[Bignum(int/str)]") {
    std::stringstream ss[2];

    Bignum i(1234);
    ss[0] << i;

    Bignum s("1234");
    ss[1] << s;

    SECTION("int", "konstruktor tesztelese int parameterrel")
    {
        CHECK(ss[0].str() == "1234");
    }

    SECTION("str", "konstruktor tesztelese string parameterrel")
    {

        CHECK(ss[1].str() == "1234");
    }
}