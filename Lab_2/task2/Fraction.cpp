#include "Fraction.h"

Fraction::Fraction(int divisible, int divisor = 1)
{
    this->divisible = divisible;
    if(divisor == 0) throw std::runtime_error("Divide by zero exception.");
    this->divisor = divisor;
}

int Fraction::getDivisible()
{
    return divisible; 
}

int Fraction::getDivisor()
{
    return divisor;
}

void Fraction::setDivisible(int divisible)
{
    this->divisible = divisible;
}

void Fraction::setDivisor(int divisor)
{
    if(divisor == 0) throw std::runtime_error("Divide by zero exception.");
    this->divisor = divisor;
}

void Fraction::reduce()
{
    int gcd = std::gcd(divisible, divisor);
    divisible /= gcd;
    divisor /= gcd;
}

Fraction Fraction::operator+(Fraction &fraction)
{
    int newDivisible = divisible * fraction.divisor + fraction.divisible * divisor;
    int newDivisor = divisor * fraction.divisor;
    return Fraction(newDivisible, newDivisor);
}

Fraction Fraction::operator-(Fraction &fraction)
{
    int newDivisible = divisible * fraction.divisor - fraction.divisible * divisor;
    int newDivisor = divisor * fraction.divisor;
    return Fraction(newDivisible, newDivisor);
}

Fraction Fraction::operator*(Fraction& fraction) 
{
    int newDivisible = divisible * fraction.divisible;
    int newDivisor = divisor * fraction.divisor;
    return Fraction(newDivisible, newDivisor);
}
    
Fraction Fraction::operator/(Fraction& fraction)
{
    if (fraction.divisible == 0) throw std::invalid_argument("Cannot divide by zero");
    int newDivisible = divisible * fraction.divisor;
    int newDivisor = divisor * fraction.divisible;
    return Fraction(newDivisible, newDivisor);
}