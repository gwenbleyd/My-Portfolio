#ifndef COMPLEX_NUMBER_COMPLEX_H
#define COMPLEX_NUMBER_COMPLEX_H

#include <iostream>
#include <cmath>
#include <string>

class complex {
public:
    complex();
    complex(double, double);
    ~complex();
    complex &operator=(complex const &);
    complex operator+(complex const &) const ;
    complex operator/(complex const &) const;
    complex operator-(complex const &) const;
    complex operator*(complex const &) const;
    complex operator*(double) const;
    complex operator/(double) const;
    complex operator+() const;
    complex operator-() const;
    bool operator ==(complex const &) const;
    bool operator !=(complex const &) const;
    friend std::ostream& operator<< (std::ostream&, complex &);
    friend std::istream& operator>> (std::istream &, complex &);
    friend complex cpow(complex &, double);
    friend void print(complex const &);
private:
    double radius;
    double corner;
};

#endif
