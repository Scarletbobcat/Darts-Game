#include "point.h"

Point::Point(Fraction x1, Fraction y1) {
    x = x1;
    y = y1;
}

Point Point::operator+(Point rhs) {
    return Point(x + rhs.x , y + rhs.y);
}

Point Point::operator-(Point rhs) {
    return Point(x - rhs.x, y - rhs.y);
}

Point Point::operator*(Fraction rhs) {
    return Point(x * rhs, y * rhs);
}

Fraction Point::operator*(Point rhs) {
    return (x * rhs.y - y * rhs.x);
}

bool Point::operator!=(Point rhs) {
    return ((x != rhs.x) != (y != rhs.y));
}

bool Point::operator==(Point rhs) {
    return ((x == rhs.x) && (y == rhs.y));
}

std::istream &operator>>(std::istream &is, Point &p) {
    Fraction
            f, s;
    char
            comma, parenthesis;

    is >> parenthesis >> f >> comma >> s >> parenthesis;

    p = Point(f, s);

    return is;
}

std::ostream &operator<<(std::ostream &os, Point p) {
    os << "(" << p.getX() << ", " << p.getY() << ")\n";

    return os;
}
