#ifndef INC_2BEAD_BIGNUM_H
#define INC_2BEAD_BIGNUM_H


#include <ostream>
#include <string>


class Bignum {
private:
    class Node {
    private:
        Node* pLeft;
        Node* pRight;

    public:
        int value;

        explicit Node(int value) : pLeft(this), value(value), pRight(this) {}
        ~Node() { unlink(); pLeft = pRight = nullptr; }

        void unlink() { pLeft->pRight = pRight; pRight->pLeft = pLeft; pLeft = pRight = this; }
        void linkLeftOf(Node* ofNode);
        void linkRightOf(Node* ofNode);
        Node* left() {return pLeft;};
        Node* right() {return pRight;};
    };

    Node* _first = new Node(-1);

    /*void push(Node* prev, int n, Node* next);
    void push_first(int n) { push(nullptr, n, _first); }
    void push_last(int n) { push(_last, n, nullptr); }*/
    void copy(const Bignum& other);
    void destruct();
    int length() const;

public:
    /*class Enor {
    public:
        enum MODE {
            F2L, L2F
        };

    private:
        Bignum* _bigNum;
        Node* _ptr = nullptr;
        Enor::MODE _m;

    public:
        Enor(Bignum* bigNum, MODE m) : _bigNum(bigNum), _m(m) {}

        void first() { if (_m == L2F) _ptr = _bigNum->_last; else _ptr = _bigNum->_first; }
        void next() { if (_m == L2F) _ptr = _ptr->prev; else _ptr = _ptr->next; }
        int current() { return _ptr->value; }
        bool end() { return _ptr == nullptr; }
    };*/

    Bignum() = default;
    explicit Bignum(int n);
    explicit Bignum(const char* str);
    Bignum(const Bignum& other) { copy(other); }
    ~Bignum() { destruct(); delete _first; }

    //Enor createEnor(Enor::MODE mode = Enor::MODE::F2L) { return {this, mode}; }

    Bignum& operator=(const Bignum& rhs);

    friend std::ostream& operator<<(std::ostream& os, Bignum& bigNum);
    friend std::istream& operator>>(std::istream& is, Bignum& bigNum);
    friend Bignum& operator+(const Bignum& lhs, const Bignum& rhs);
    friend Bignum& operator*(const Bignum& lhs, const Bignum& rhs);
};


#endif //INC_2BEAD_BIGNUM_H
