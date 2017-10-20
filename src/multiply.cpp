#include "Bignum.h"

/**
 * helper method for Karatsuba multiplication
 * @param m : int
 * @param num : Bignum
 * @return - num * 10^m
 */
Bignum& times10to(int m, const Bignum& num) {
    auto res = new Bignum(num);
    for (int i = 0; i < m; ++i)
        (new Bignum::Node(0))->linkLeftOf(res->_first);
    return *res;
}

/**
 * helper method for Karatsuba multiplication
 * @param n : int
 * @param bignum : Bignum
 * @return - num *n
 */
Bignum& mulWithLessThanTen(int n, const Bignum& bignum) {
    if (n == 0)
        return *(new Bignum(0));
    if (n == 1)
        return *(new Bignum(bignum));

    auto result = new Bignum();

    int carry = 0;
    for (Bignum::Node* p = bignum._first->left(); p != bignum._first; p = p->left())
    {
        int prod = carry + n * p->value;
        (new Bignum::Node(prod % 10))->linkRightOf(result->_first);
        carry = prod / 10;
    }
    if (carry) (new Bignum::Node(carry))->linkRightOf(result->_first);

    return *result;
}

/**
 * Multiplication of 2 big numbers using the Karatsuba algorithm
 * https://en.wikipedia.org/wiki/Karatsuba_algorithm
 * @param lhs - left hand side of the operation
 * @param rhs - right hand side of the operation
 * @return - result of the multiplcation
 */
Bignum& operator*(const Bignum& lhs, const Bignum& rhs) {
    if (lhs.length() == 1)
        return mulWithLessThanTen(lhs._first->right()->value, rhs);

    if (rhs.length() == 1)
        return mulWithLessThanTen(rhs._first->right()->value, lhs);

    int m = (lhs.length() < rhs.length() ? lhs.length() : rhs.length()) - 1;
    Bignum x1, x0, y1, y0;
    x0 = lhs;
    y0 = rhs;

    for (int i = lhs.length() - m; i > 0; --i)
        (x0._first->right())->linkLeftOf(x1._first);
    for (int i = rhs.length() - m; i > 0; --i)
        (y0._first->right())->linkLeftOf(y1._first);

    Bignum z2 = x1 * y1;
    Bignum z1 = x1 * y0 + x0 * y1;
    Bignum z0 = x0 * y0;

    return times10to(2 * m, z2) + times10to(m, z1) + z0;
}

