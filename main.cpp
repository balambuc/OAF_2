#include <iostream>
#include <cstdlib>
#include "BigNum.h"


int main() {
    system("chcp 65001");
    BigNum bn(123456);
    BigNum::Enor enorF2L = bn.createEnor();
    BigNum::Enor enorL2F = bn.createEnor(BigNum::Enor::MODE::L2F);
    for (enorF2L.first(); !enorF2L.end(); enorF2L.next())
        std::cout << enorF2L.current()->value << ", ";
    std::cout << std::endl;

    for (enorL2F.first(); !enorL2F.end(); enorL2F.next())
        std::cout << enorL2F.current()->value << ", ";
    std::cout << std::endl;
    std::cout << bn.length() << std::endl;
    BigNum bn2(bn);
    BigNum bn3 = bn2;
    BigNum j(5);
    std::cout << BigNum(123) * BigNum(4567) << std::endl;
    std::cout << BigNum(7891011) * BigNum(3) << std::endl;
    std::cout << BigNum(7891011) * BigNum(12) << std::endl;
    std::cout << BigNum(7891011) * BigNum(123) << std::endl;
    std::cout << BigNum(7891011) * BigNum(1234) << std::endl;
    std::cout << BigNum(7891011) * BigNum(12345) << std::endl;
    std::cout << BigNum(7891011) * BigNum(123456) << std::endl;
    std::cin >> bn3;
    std::cout << "A bn3-as nagyszám: " << bn3 << std::endl;

    return 0;
}