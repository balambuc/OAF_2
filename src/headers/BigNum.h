#ifndef INC_2BEAD_BIGNUM_H
#define INC_2BEAD_BIGNUM_H


#include <ostream>
#include <string>


class BigNum {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;

        Node(Node* prev, int value, Node* next) : prev(prev), value(value), next(next) {}
    };

    Node* _first = nullptr;
    Node* _last = nullptr;

    void push(Node* prev, int n, Node* next);
    void push_first(int n) { push(nullptr, n, _first); }
    void push_last(int n) { push(_last, n, nullptr); }
    void copy(const BigNum& other);
    void destruct();
    int length() const;

public:
    class Enor {
    public:
        enum MODE {
            F2L, L2F
        };

    private:
        BigNum* _bigNum;
        Node* _ptr = nullptr;
        Enor::MODE _m;

    public:
        Enor(BigNum* bigNum, MODE m) : _bigNum(bigNum), _m(m) {}

        void first() { if (_m == L2F) _ptr = _bigNum->_last; else _ptr = _bigNum->_first; }

        void next() { if (_m == L2F) _ptr = _ptr->prev; else _ptr = _ptr->next; }

        int current() { return _ptr->value; }

        bool end() { return _ptr == nullptr; }
    };

    BigNum() = default;
    explicit BigNum(int n);
    explicit BigNum(const char* str);
    BigNum(const BigNum& other) { copy(other); }
    ~BigNum() { destruct(); }

    Enor createEnor(Enor::MODE mode = Enor::MODE::F2L) { return {this, mode}; }

    BigNum& operator=(const BigNum& rhs);

    friend std::ostream& operator<<(std::ostream& os, BigNum& bigNum);
    friend std::istream& operator>>(std::istream& is, BigNum& bigNum);
    friend BigNum& operator+(const BigNum& lhs, const BigNum& rhs);
    friend BigNum& operator*(const BigNum& lhs, const BigNum& rhs);
};


#endif //INC_2BEAD_BIGNUM_H
