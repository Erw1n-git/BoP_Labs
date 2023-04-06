#include <iostream>
#include <stdlib.h>

#include "numeric"

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {

    private:
        int divisible;
        int divisor;

    public:
        Fraction() : Fraction(0, 1) { }
        Fraction(int divisible, int divisor);

        int getDivisible();
        int getDivisor();

        void setDivisible(int divisible);
        void setDivisor(int divisor);

        void reduce();

        Fraction operator+(Fraction& fraction);
        Fraction operator-(Fraction& fraction);
        Fraction operator*(Fraction& fraction);
        Fraction operator/(Fraction& fraction);

};

#endif