#include <iostream>
#include "catch.hpp"
#include "Bignum.h"

TEST_CASE("Nagy szamok szorzasa", "[operator*]") {
    std::stringstream ss[2];

    SECTION("szorzas 0-val mindket iranybol")
    {
        ss[0] << Bignum(1234) * Bignum(0);
        ss[1] << Bignum(0) * Bignum(1234);

        CHECK(ss[0].str() == "0");
        CHECK(ss[1].str() == "0");

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("szorzas 1-el mindket iranybol")
    {
        ss[0] << Bignum(1234) * Bignum(1);
        ss[1] << Bignum(1) * Bignum(1234);

        CHECK(ss[0].str() == "1234");
        CHECK(ss[1].str() == "1234");

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("kommutativitas vizsgalata")
    {
        ss[0] << Bignum(1234) * Bignum(5678);
        ss[1] << Bignum(5678) * Bignum(1234);

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("asszociativitas vizsgalata")
    {
        ss[0] << ( Bignum(1234) * Bignum(5678) ) * Bignum(91011);
        ss[1] << Bignum(1234) * ( Bignum(5678) * Bignum(91011) );

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("ket nagyon nagy szam szorzata")
    {
        ss[0] << Bignum("1234567891011121314151617181920") * Bignum("212223242526272829303132333435");

        CHECK(ss[0].str() == "1446791133537394143454749515355");

        ss[0].str("");
    }

    SECTION("ket random szam szorzata 10-szer")
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        int a,b;
        for (int i = 0; i < 10; ++i)
        {
            a = std::rand() % 10000; // így nem csordul túl az int * int szorzat
            b = std::rand() % 10000;
            Bignum bNa(a);
            Bignum bNb(b);
            ss[0] << (bNa * bNb);
            ss[1] << (a * b);

            CHECK(ss[0].str() == ss[1].str());

            ss[0].str("");
            ss[1].str("");
        }
    }
}