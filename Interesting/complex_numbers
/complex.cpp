#include "complex.h"

complex::complex(double __radius, double __corner) {
    radius = __radius;
    corner = __corner;
}

complex::complex() {
    radius = 0;
    corner = 0;
}

complex::~complex() = default;

complex complex::operator*(complex const &right) const {
    return complex(this->radius*right.radius, this->corner+right.corner);
}

complex complex::operator*(double x) const {
    return complex(x*this->radius, this->corner);
}

complex complex::operator+(complex const &right) const {
    return complex(sqrt(pow(this->radius*cos(this->corner) + right.radius*cos(right.corner),2) + pow(this->radius*sin(this->corner) + right.radius*sin(right.corner),2)),
            atan((this->radius*cos(this->corner) + right.radius*cos(right.corner))/((this->radius*sin(this->corner) + right.radius*sin(right.corner)))));
}

complex complex::operator/(complex const &right) const {
    return complex(this->radius/right.radius, this->corner - right.corner);
}

complex complex::operator/(double x) const {
    return complex(this->radius / x, this->corner);
}

complex complex::operator-(complex const &right) const {
    return complex(sqrt(pow(this->radius*cos(this->corner) - right.radius*cos(right.corner),2) + pow(this->radius*sin(this->corner) - right.radius*sin(right.corner),2)),
            atan((this->radius*cos(this->corner) - right.radius*cos(right.corner))/((this->radius*sin(this->corner) - right.radius*sin(right.corner)))));;
}

complex complex::operator+() const {
    return *this;
}

complex complex::operator-() const {
    return complex(-this->radius, corner);
}

complex &complex::operator=(complex const &right) = default;

bool complex::operator==(complex const &right) const {
    return this->radius == right.radius && this->corner == right.corner;
}

bool complex::operator!=(complex const &right) const{
    return this->radius != right.radius && this->corner != right.corner;
}

void print(complex const &x) {
    if(x.radius*sin(x.corner) < 0){
        std::cout<<x.radius*cos(x.corner)<<" - i*"<<fabs(x.radius*sin(x.corner))<<std::endl;
    } else{
        std::cout<<x.radius*cos(x.corner)<<" + i*"<<x.radius*sin(x.corner)<<std::endl;
    }
}

complex cpow(complex &x, double y){
    return complex(pow(x.radius, y), x.corner*y);
}

std::ostream &operator<<(std::ostream &out, complex &x) {
    if(x.corner < 0){
        out<<x.radius<<"*(cos("<<fabs(x.corner)<<") - i*sin("<<fabs(x.corner)<<"))";
    } else{
        out<<x.radius<<"*(cos("<<x.corner<<") + i*sin("<<x.corner<<"))";
    }
    return out;
}

std::istream& operator>> (std::istream &in, complex & x){
    in >> x.radius;
    in >> x.corner;
    return in;
}
