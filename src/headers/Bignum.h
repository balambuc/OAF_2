#ifndef INC_2BEAD_BIGNUM_H
#define INC_2BEAD_BIGNUM_H


#include <ostream>
#include <string>
#include "Bignum_exceptions.h"


class Bignum {
private:
    class Node {
    private:
        Node* pLeft;
        Node* pRight;

    public:
        int value;

        explicit Node(int value) : pLeft(this), value(value), pRight(this) {}
        ~Node() {
            unlink();
            pLeft = pRight = nullptr;
        }

        void unlink() {
            pLeft->pRight = pRight;
            pRight->pLeft = pLeft;
            pLeft = pRight = this;
        }
        void linkLeftOf(Node* ofNode);
        void linkRightOf(Node* ofNode);
        Node* left() { return pLeft; };
        Node* right() { return pRight; };
    };

    Node* _first = new Node(-1);

    void copy(const Bignum& other);
    void destruct();
    int length() const;
    friend Bignum& times10to(int m, const Bignum& num);
    friend Bignum& mulWithLessThanTen(int n, const Bignum& bignum);

public:
    class Enor {
    private:
        Bignum* _bignum;
        Node* _ptr;

    public:
        explicit Enor(Bignum* bignum) : _bignum(bignum), _ptr(bignum->_first) {}

        void first() { next(); }
        void next() { _ptr = _ptr->right(); }
        int current() { return _ptr->value; }
        bool end() { return _ptr == _bignum->_first; }
    };

    Bignum() = default;
    explicit Bignum(int n);
    explicit Bignum(const char* str);
    Bignum(const Bignum& other) { copy(other); }
    ~Bignum() {
        destruct();
        delete _first;
    }

    Enor createEnor() { return *(new Enor(this)); }

    Bignum& operator=(const Bignum& rhs);

    friend std::ostream& operator<<(std::ostream& os, Bignum& bigNum);
    friend std::istream& operator>>(std::istream& is, Bignum& bigNum);
    friend Bignum& operator+(const Bignum& lhs, const Bignum& rhs);
    friend Bignum& operator*(const Bignum& lhs, const Bignum& rhs);
};


#endif //INC_2BEAD_BIGNUM_H
