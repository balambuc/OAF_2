#include <iostream>
#include "BigNum.h"


int main() {
    std::cout << BigNum(123) * BigNum(4567) << std::endl;
    std::cout << BigNum(7891011) * BigNum(3) << std::endl;
    std::cout << BigNum(7891011) * BigNum(12) << std::endl;
    std::cout << BigNum(7891011) * BigNum(123) << std::endl;
    std::cout << BigNum(7891011) * BigNum(1234) << std::endl;
    std::cout << BigNum(7891011) * BigNum(12345) << std::endl;
    std::cout << BigNum(7891011) * BigNum(7234561) << std::endl;
    return 0;
}