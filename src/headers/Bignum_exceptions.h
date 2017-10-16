#ifndef INC_2BEAD_BIGNUM_EXCEPTIONS_H
#define INC_2BEAD_BIGNUM_EXCEPTIONS_H

#include <exception>


class NotNaturalNum : public std::exception
{
    const char* what() const throw() override { return "Not a natural number!";}
};

class StartsWithZero : public std::exception
{
    const char* what() const throw() override { return "Number cannot start with zero!";}
};



#endif //INC_2BEAD_BIGNUM_EXCEPTIONS_H
