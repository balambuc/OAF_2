#include <cstring>
#include <iostream>
#include "Bignum.h"


/**
 * Bignum constructor
 * @param n - number to hold
 */
Bignum::Bignum(int n) {
    if (n < 0)
        throw *(new NotNaturalNum);
    if(n == 0)
        (new Node(0))->linkRightOf(_first);
    while (n  != 0)
    {
        (new Node(n % 10))->linkRightOf(_first);
        n /= 10;
    }
}

/**
 * Bignum constructor
 * @param n - number to hold
 */
Bignum::Bignum(const char* str) {
    if(str[0] == '0' && std::strlen(str) > 1)
        throw *(new StartsWithZero);
    for (int i = 0; i < std::strlen(str); ++i)
    {
        if(str[i] < '0' || str[i] > '9')
            throw *(new NotNaturalNum);
        (new Node(str[i] - '0'))->linkLeftOf(_first);
    }

}

/**
 * Addition of two Bignums, using the long summation method
 * @param lhs - left hand side of the operation
 * @param rhs - right hand side of the operation
 * @return - result of the operation
 */
Bignum operator+(const Bignum& lhs, const Bignum& rhs) {
    auto result = new Bignum();

    Bignum::Node* pLhs = lhs._first->left();
    Bignum::Node* pRhs = rhs._first->left();

    int carry = 0;

    while (pLhs != lhs._first || pRhs != rhs._first)
    {
        int sum = (pLhs != lhs._first ? pLhs->value : 0) + carry + (pRhs != rhs._first ? pRhs->value : 0);
        (new Bignum::Node(sum % 10))->linkRightOf(result->_first);
        carry = sum / 10;

        if (pLhs != lhs._first) pLhs = pLhs->left();
        if (pRhs != rhs._first) pRhs = pRhs->left();
    }
    if (carry) (new Bignum::Node(carry))->linkRightOf(result->_first);

    return *result;
}

/**
 * Custom assignment operator for Bignum
 * @param rhs - assign this
 * @return - to this
 */
Bignum& Bignum::operator=(const Bignum& rhs) {
    if (&rhs == this) return *this;
    destruct();
    copy(rhs);
    return *this;
}

/**
 * Custom outstream operator for bignum
 * @param os - any kind of outstream
 * @param bignum - any Bignum
 * @return - outsream after operation
 */
std::ostream& operator<<(std::ostream& os, const Bignum& bignum) {
    for (Bignum::Node* p = bignum._first->right(); p != bignum._first ; p = p->right())
        os << p->value;
    return os;
}

/**
 * Custom instream operator for bignum
 * @param is - any kind of instream
 * @param bignum - any Bignum
 * @return - instream after operation
 */
std::istream& operator>>(std::istream& is, Bignum& bigNum) {
    std::string num;
    is >> num;
    Bignum temp(num.c_str());
    bigNum = temp;
    return is;
}

/**
 * Destructor helper-method
 */
void Bignum::destruct() {
    while (_first->right() != _first)
        delete _first->right();
}

/**
 * Copy ctor helper-method
 * @param other - bignum to be copied
 */
void Bignum::copy(const Bignum& other) {
    for (Node* p = other._first->right(); p != other._first; p = p->right())
        (new Node(p->value))->linkLeftOf(_first);
}

/**
 * Link the node to the left of 'ofNode'
 * @param ofNode - node which will be on the right side of *this after the operation
 */
void Bignum::Node::linkLeftOf(Bignum::Node* ofNode) {
    unlink();
    Node* prev = ofNode->pLeft;
    pLeft = prev;
    pRight = ofNode;
    prev->pRight = ofNode->pLeft = this;
}

/**
 * Link *this to the right of 'ofNode'
 * @param ofNode - node which will be on the left side of *this after the operation
 */
void Bignum::Node::linkRightOf(Bignum::Node* ofNode) {
    unlink();
    Node* next = ofNode->pRight;
    pRight = next;
    pLeft = ofNode;
    next->pLeft = ofNode->pRight = this;
}

/**
 * Gives the length of the bignum
 * @return - the length
 */
int Bignum::length() const {
    Node* p = _first->right();
    int i;
    for (i = 0; p != _first; ++i, p = p->right());
    return i;
}