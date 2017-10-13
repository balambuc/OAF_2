#include "catch.hpp"
#include "BigNum.h"

TEST_CASE("<< es >> operatorok", "operator(>>/<<)") {
    std::stringstream ss[3];

    BigNum i(1234);

    std::string s = "5678";
    ss[1] << s;

    SECTION("<<")
    {
        ss[0] << i;
        CHECK(ss[0].str() == "1234");
    }

    SECTION(">>")
    {
        BigNum in;
        ss[1] >> in;
        BigNum::Enor en = in.createEnor();
        for(en.first(); !en.end(); en.next())
            ss[2] << en.current();
        CHECK(ss[2].str() == "5678");
    }
}