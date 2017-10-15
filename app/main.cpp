#include <iostream>
#include "Bignum.h"


int main() {
    std::cout << Bignum(123) * Bignum(4567) << std::endl;
    std::cout << Bignum(7891011) * Bignum(3) << std::endl;
    std::cout << Bignum(7891011) * Bignum(12) << std::endl;
    std::cout << Bignum(7891011) * Bignum(123) << std::endl;
    std::cout << Bignum(7891011) * Bignum(1234) << std::endl;
    std::cout << Bignum(7891011) * Bignum(12345) << std::endl;
    std::cout << Bignum(7891011) * Bignum(7234561) << std::endl;
    return 0;
}