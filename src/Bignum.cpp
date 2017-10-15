#include <cstring>
#include <iostream>
#include "Bignum.h"


Bignum::Bignum(int n) {
    while (n / 10 != 0)
    {
        (new Node(n % 10))->linkRightOf(_first);
        n /= 10;
    }
    (new Node(n))->linkRightOf(_first);
}

Bignum::Bignum(const char* str) {
    for (int i = 0; i < std::strlen(str); ++i)
        (new Node(str[i] - '0'))->linkLeftOf(_first);
}

Bignum& operator+(const Bignum& lhs, const Bignum& rhs) {
    auto result = new Bignum();

    Bignum::Node* pLhs = lhs._first->left();
    Bignum::Node* pRhs = rhs._first->left();

    int sum, carry = 0;

    while (pLhs != lhs._first || pRhs != rhs._first)
    {
        sum = (pLhs != lhs._first ? pLhs->value : 0) + carry + (pRhs != rhs._first ? pRhs->value : 0);
        (new Bignum::Node(sum % 10))->linkRightOf(result->_first);
        carry = sum / 10;

        if (pLhs != lhs._first) pLhs = pLhs->left();
        if (pRhs != rhs._first) pRhs = pRhs->left();
    }
    if (carry) (new Bignum::Node(carry))->linkRightOf(result->_first);

    return *result;
}

//Karatsuba ld: https://en.wikipedia.org/wiki/Karatsuba_algorithm
Bignum& operator*(const Bignum& lhs, const Bignum& rhs) {
    if(lhs._first->right()->value == 0 && lhs._first->right()->right() == lhs._first)
        return  *(new Bignum(0));
    if(rhs._first->right()->value == 0 && rhs._first->right()->right() == rhs._first)
        return  *(new Bignum(0));
    if(lhs._first->right()->value == 1 && lhs._first->right()->right() == lhs._first)
        return  *(new Bignum(rhs));
    if(rhs._first->right()->value == 1 && rhs._first->right()->right() == rhs._first)
        return  *(new Bignum(lhs));

    int B = 10;
    int m = (lhs.length() < rhs.length() ? lhs.length() : rhs.length());

    auto result = new Bignum(lhs);

    return *result;
}

Bignum& Bignum::operator=(const Bignum& rhs) {
    if (&rhs == this) return *this;
    destruct();
    copy(rhs);
    return *this;
}

std::ostream& operator<<(std::ostream& os, Bignum& bigNum) {
    for (Bignum::Node* p = bigNum._first->right(); p != bigNum._first ; p = p->right())
        os << p->value;
    return os;
}

std::istream& operator>>(std::istream& is, Bignum& bigNum) {
    std::string num;
    is >> num;
    Bignum temp(num.c_str());
    bigNum = temp;
    return is;
}

void Bignum::destruct() {
    while (_first->right() != _first)
        delete _first->right();
}

void Bignum::copy(const Bignum& other) {
    for (Node* p = other._first->right(); p != other._first; p = p->right())
        (new Node(p->value))->linkLeftOf(_first);
}

int Bignum::length() const {
    Node* p = _first->right();
    int i;
    for (i = 1; p != _first; ++i, p = p->right());
    return i;
}

void Bignum::Node::linkLeftOf(Bignum::Node* ofNode) {
    unlink();
    Node* prev = ofNode->pLeft;
    pLeft = prev;
    pRight = ofNode;
    prev->pRight = ofNode->pLeft = this;
}

void Bignum::Node::linkRightOf(Bignum::Node* ofNode) {
    unlink();
    Node* next = ofNode->pRight;
    pRight = next;
    pLeft = ofNode;
    next->pLeft = ofNode->pRight = this;
}
