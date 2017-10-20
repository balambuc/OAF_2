#include <iostream>
#include "catch.hpp"
#include "Bignum.h"


TEST_CASE("Nagy szamok osszeadasa", "[operator+]") {
    std::stringstream ss[2];

    SECTION("0 elem vizsgalata", "0+a = a+0 = a")
    {
        ss[0] << Bignum(1234) + Bignum(0);

        CHECK(ss[0].str() == "1234");

        ss[0].str(""); //clear the stringstream
    }

    SECTION("kommutativitas vizsgalata", "a+b = b+a")
    {
        ss[0] << Bignum(1234) + Bignum(5678);
        ss[1] << Bignum(5678) + Bignum(1234);

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("asszociativitas vizsgalata", "(a+b)+c = a+(b+c)")
    {
        ss[0] << (Bignum(1234) + Bignum(5678)) + Bignum(91011);
        ss[1] << Bignum(1234) + (Bignum(5678) + Bignum(91011));

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("ket nagyon nagy szam osszege", "a+b (a,b>10^20)")
    {
        ss[0] << Bignum("1234567891011121314151617181920") + Bignum("212223242526272829303132333435");

        CHECK(ss[0].str() == "1446791133537394143454749515355");

        ss[0].str("");
    }

    SECTION("ket random szam osszege 10-szer", "a+b")
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (int i = 0; i < 10; ++i)
        {
            int a = std::rand() % 10000; // így nem csordul túl az int + int összeg
            int b = std::rand() % 10000;
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
