#include <iostream>
#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Nagy szamok osszeadasa", "[operator+]") {
    std::stringstream ss[2];

    SECTION("0 elem vizsgalata")
    {
        ss[0] << Bignum(1234) + Bignum(0);

        CHECK(ss[0].str() == "1234");

        ss[0].str(""); //clear the stringstream
    }

    SECTION("kommutativitas vizsgalata")
    {
        ss[0] << Bignum(1234) + Bignum(5678);
        ss[1] << Bignum(5678) + Bignum(1234);

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("asszociativitas vizsgalata")
    {
        ss[0] << ( Bignum(1234) + Bignum(5678) ) + Bignum(91011);
        ss[1] << Bignum(1234) + ( Bignum(5678) + Bignum(91011) );

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("ket nagyon nagy szam osszege")
    {
        ss[0] << Bignum("1234567891011121314151617181920") + Bignum("212223242526272829303132333435");

        CHECK(ss[0].str() == "1446791133537394143454749515355");

        ss[0].str("");
    }

    SECTION("ket random szam osszege 10-szer")
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        int a,b;
        for (int i = 0; i < 10; ++i)
        {
            a = std::rand() % 10000; // így nem csordul túl az int + int összeg
            b = std::rand() % 10000;
            Bignum bNa(a);
            Bignum bNb(b);
            ss[0] << (bNa + bNb);
            ss[1] << (a + b);

            CHECK(ss[0].str() == ss[1].str());

            ss[0].str("");
            ss[1].str("");
        }
    }
}
