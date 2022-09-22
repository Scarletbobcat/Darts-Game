#include "fraction.h"
#include <iostream>

#ifndef POINT_H
#define POINT_H

class Point {

private:
    Fraction x, y;
public:

    Point (Fraction x1 = 0, Fraction y1 = 0);
    ~Point() = default;

    Fraction getX() {return x;};
    Fraction getY() {return y;};

    Point operator+(Point rhs);
    Point operator-(Point rhs);
    Point operator*(Fraction rhs);
    Fraction operator*(Point rhs);
    bool operator==(Point rhs);
    bool operator!=(Point rhs);

};

std::istream &operator>>(std::istream &is, Point &p);
std::ostream &operator<<(std::ostream &os, Point p);

#endif //POINT_H
