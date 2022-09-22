#include <iostream>
#include <cstdint>

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
public:
    Fraction(int32_t _num = 0, int32_t _den = 1);
    ~Fraction() = default;

    //rhs = right hand side, as in the right hand side of the operator
    Fraction operator+(Fraction rhs);
    Fraction operator-(Fraction rhs);
    Fraction operator/(Fraction rhs);
    Fraction operator*(Fraction rhs);
    Fraction &operator=(Fraction rhs);


    bool operator==(Fraction rhs);
    bool operator!=(Fraction rhs);
    bool operator<(Fraction rhs);
    bool operator>(Fraction rhs);
    bool operator<=(Fraction rhs);
    bool operator>=(Fraction rhs);


    int getNum() { return num; }
    int getDen() { return den; }

private:
    int32_t
            num,
            den;
};

std::istream &operator>>(std::istream &is, Fraction &f);
std::ostream &operator<<(std::ostream &os, Fraction f);

#endif
