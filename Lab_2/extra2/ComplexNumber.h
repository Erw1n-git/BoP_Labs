#include <iostream>

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

class ComplexNumber{

    friend std::istream& operator>>(std::istream& in, ComplexNumber& number);
    friend std::ostream& operator<<(std::ostream& out, ComplexNumber& number);

    private:
        double real;
        double imaginary;

    public:
        ComplexNumber(double r = 0, double i = 0) : real(r), imaginary(i) { }

        double getReal() const;
        double getImaginary() const;

        ComplexNumber operator+(const ComplexNumber& number) const;
        ComplexNumber operator-(const ComplexNumber& number) const;
        ComplexNumber operator/(const ComplexNumber& number) const;
        ComplexNumber operator*(const ComplexNumber& number) const;
};

#endif