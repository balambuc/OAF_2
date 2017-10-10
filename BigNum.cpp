#include <cstring>
#include <iostream>
#include "BigNum.h"


BigNum::BigNum(int n) {
    while (n / 10 != 0)
    {
        push_first(n % 10);
        n /= 10;
    }
    push_first(n);
}

BigNum::BigNum(const char* str) {
    for (int i = 0; i < std::strlen(str); ++i)
        push_last(str[i] - '0');
}

void BigNum::push(Node* prev, int n, Node* next) {
    auto p = new Node(prev, n, next);
    prev ? prev->next = p : _first = p;
    next ? next->prev = p : _last = p;
}

BigNum& operator+(const BigNum& lhs, const BigNum& rhs) {
    auto result = new BigNum();

    BigNum::Node* pLhs = lhs._last;
    BigNum::Node* pRhs = rhs._last;

    int sum, carry = 0;

    while (pLhs || pRhs)
    {
        sum = (pLhs ? pLhs->value : 0) + carry + (pRhs ? pRhs->value : 0);
        result->push_first(sum % 10);
        carry = sum / 10;

        if (pLhs) pLhs = pLhs->prev;
        if (pRhs) pRhs = pRhs->prev;
    }
    if (carry) result->push_first(carry);

    return *result;
}

/**
 * This is magic...basically long multiplication, buuuuuut IDK
 * @param lhs - left side of multiplication
 * @param rhs - right side of multiplication
 * @return result - a reference to the result of the operation
 */
BigNum& operator*(const BigNum& lhs, const BigNum& rhs) {
    auto result = new BigNum(0);
    BigNum lHand = BigNum();
    BigNum rHand = BigNum();

    if (lhs.length() <= rhs.length())
    {
        lHand = lhs;
        rHand = rhs;
    }
    else
    {
        lHand = rhs;
        rHand = lhs;
    }

    BigNum::Enor lhsEnor = lHand.createEnor(BigNum::Enor::MODE::L2F);
    BigNum::Enor rhsEnor = rHand.createEnor(BigNum::Enor::MODE::L2F);
    BigNum::Node* starter = result->_last;
    int mul, carry;

    for (lhsEnor.first(); !lhsEnor.end(); lhsEnor.next())
    {
        carry = 0;
        BigNum::Node* p = starter;
        for (rhsEnor.first(); !rhsEnor.end(); rhsEnor.next())
        {
            mul = lhsEnor.current()->value * rhsEnor.current()->value + carry + (p ? p->value : 0);
            carry = mul / 10;
            mul = mul % 10;
            if (p)
            {
                p->value = mul;
                p = p->prev;
            }
            else result->push_first(mul);
        }
        if (carry) result->push_first(carry);
        starter = starter->prev;
    }

    return *result;
}

BigNum& BigNum::operator=(const BigNum& rhs) {
    if (&rhs == this) return *this;
    destruct();
    copy(rhs);
    return *this;
}

std::ostream& operator<<(std::ostream& os, BigNum& bigNum) {
    BigNum::Enor enorF2L = bigNum.createEnor();
    for (enorF2L.first(); !enorF2L.end(); enorF2L.next())
        os << enorF2L.current()->value;
    return os;
}

std::istream& operator>>(std::istream& is, BigNum& bigNum) {
    std::string num;
    is >> num;
    BigNum temp(num.c_str());
    bigNum = temp;
    return is;
}

void BigNum::destruct() {
    Node* p;
    while (_first != nullptr)
    {
        p = _first;
        _first = p->next;
        delete p;
    }
    _last = nullptr;
}

void BigNum::copy(const BigNum& other) {
    for (Node* p = other._first; p != nullptr; p = p->next)
        push_last(p->value);
}

int BigNum::length() const {
    Node* p = _first;
    int i;
    for (i = 0; p; ++i, p = p->next);
    return i;
}


