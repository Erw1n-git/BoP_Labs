#include "Fraction.h"

// ====== CONSTRUCTORS ======
Fraction::Fraction(int numerator, int denominator = 1)
{
    setNumerator(numerator);
    setDenominator(denominator);
}

// ====== GETTERS ======
int Fraction::getNumerator() const
{
    return numerator; 
}

int Fraction::getDenominator() const
{
    return denominator;
}

// ====== SETTERS ======
void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
    if(denominator == 0) throw std::runtime_error("Divide by zero exception.");
    this->denominator = denominator;
}

// ====== OTHERS ======
void Fraction::reduce()
{
    int _gcd = std::gcd(numerator, denominator);
    numerator /= _gcd;
    denominator /= _gcd;
}

// ====== OPERATORS ======
Fraction operator+(Fraction& f1, Fraction& f2)
{
    int newNumerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int newDenominator = f1.denominator * f2.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction operator-(Fraction& f1, Fraction& f2)
{
    int newNumerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    int newDenominator = f1.denominator * f2.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction operator*(Fraction& f1, Fraction& f2) 
{
    int newNumerator = f1.numerator * f2.numerator;
    int newDenominator = f1.denominator * f2.denominator;
    return Fraction(newNumerator, newDenominator);
}
    
Fraction operator/(Fraction& f1, Fraction& f2)
{
    if (f1.numerator == 0) throw std::invalid_argument("Cannot divide by zero");
    int newNumerator = f1.numerator * f2.denominator;
    int newDenominator = f1.denominator * f2.numerator;
    return Fraction(newNumerator, newDenominator);
}

bool operator<(Fraction& f1, Fraction& f2)
{
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator<=(Fraction& f1, Fraction& f2)
{
    return f1.numerator * f2.denominator <= f2.numerator * f1.denominator;
}

bool operator>(Fraction& f1, Fraction& f2)
{
    return f1.numerator * f2.denominator > f2.numerator * f1.denominator;
}

bool operator>=(Fraction& f1, Fraction& f2)
{
    return f1.numerator * f2.denominator >= f2.numerator * f1.denominator;
}

std::ostream& operator<<(std::ostream& out, Fraction& f1)
{
    int integerPart = f1.numerator / f1.denominator; 
    int newNumerator = f1.numerator % f1.denominator;
    int newDenominator = f1.denominator;

    if (newNumerator == 0) 
    { 
        if (integerPart == 0) { 
            out << "0";
        } 
        else 
        {
            out << integerPart;
        }
    } 
    else if (integerPart == 0) 
    { 
        out << newNumerator << "/" << newDenominator; 
    } 
    else 
    { 
        out << "(" << integerPart << ") " << newNumerator << "/" << newDenominator;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f1)
{
    int numerator, denominator;
    char c;
    in >> numerator >> c >> denominator;
    if(c != '/')
    {
        in.setstate(std::ios_base::failbit); // Indicate input error
        return in;
    }

    f1 = Fraction(numerator, denominator);
    return in;
}