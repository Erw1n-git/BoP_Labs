#include <iostream>
#include <stdlib.h>
#include <numeric>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {

    friend std::ostream& operator<<(std::ostream& out, Fraction& f1);
    friend std::istream& operator>>(std::istream& in, Fraction& f1);
    friend Fraction operator+(Fraction& f1, Fraction& f2);
    friend Fraction operator-(Fraction& f1, Fraction& f2);
    friend Fraction operator*(Fraction& f1, Fraction& f2);
    friend Fraction operator/(Fraction& f1, Fraction& f2);
    friend bool operator<(Fraction& f1, Fraction& f2);
    friend bool operator<=(Fraction& f1, Fraction& f2);
    friend bool operator>(Fraction& f1, Fraction& f2);
    friend bool operator>=(Fraction& f1, Fraction& f2);

    private:
        int numerator;
        int denominator;

    public:
        Fraction() : Fraction(0, 1) { }
        Fraction(int numerator, int denominator);

        int getNumerator() const;
        int getDenominator() const;

        void setNumerator(int numerator);
        void setDenominator(int denominator);

        void reduce();

};

#endif