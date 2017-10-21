#include <iostream>
#include "catch.hpp"


#define private public

#include "Bignum.h"


TEST_CASE("szorzas segedfuggvenyei", "[operator*]") {
    std::stringstream ss[2];

    SECTION("times10to", "a*10^n")
    {
        ss[0] << times10to(3, *(new Bignum(123)));
        CHECK(ss[0].str() == "123000");
        ss[0].str("");
    }

    SECTION("mulWithLessThanTen", "a*b (1 < b < 10)")
    {
        for (int i = 0; i < 11; ++i)
        {
            ss[0] << mulWithLessThanTen(i, *(new Bignum(123)));
            ss[1] << (i * 123);

            CHECK(ss[0].str() == ss[1].str());

            ss[0].str("");
            ss[1].str("");
        }
    }
}

TEST_CASE("Nagy szamok szorzasa", "[operator*]") {
    std::stringstream ss[2];

    SECTION("szorzas 0-val mindket iranybol", "0a=a0=0")
    {
        ss[0] << Bignum(1234) * Bignum(0);
        ss[1] << Bignum(0) * Bignum(1234);

        CHECK(ss[0].str() == "0");
        CHECK(ss[1].str() == "0");

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("szorzas 1-el mindket iranybol", "1a=a1=a")
    {
        ss[0] << Bignum(1234) * Bignum(1);
        ss[1] << Bignum(1) * Bignum(1234);

        CHECK(ss[0].str() == "1234");
        CHECK(ss[1].str() == "1234");

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("kommutativitas vizsgalata", "ab=ba")
    {
        ss[0] << Bignum(1234) * Bignum(5678);
        ss[1] << Bignum(5678) * Bignum(1234);

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("asszociativitas vizsgalata", "(ab)c=a(bc)")
    {
        ss[0] << (Bignum(1234) * Bignum(5678)) * Bignum(91011);
        ss[1] << Bignum(1234) * (Bignum(5678) * Bignum(91011));

        CHECK(ss[0].str() == ss[1].str());

        ss[0].str("");
        ss[1].str("");
    }

    SECTION("ket nagyon nagy szam szorzata", "ab (a,b>10^20)")
    {
        ss[0] << Bignum("1234567891011121314151617181920") * Bignum("212223242526272829303132333435");

        CHECK(ss[0].str() == "262004000949202360313780607936863459388689455414248493495200");

        ss[0].str("");
    }

    SECTION("ket random szam szorzata 10-szer", "ab")
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (int i = 0; i < 10; ++i)
        {
            int a = std::rand() % 10000; // így nem csordul túl az int * int szorzat
            int b = std::rand() % 10000;
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
