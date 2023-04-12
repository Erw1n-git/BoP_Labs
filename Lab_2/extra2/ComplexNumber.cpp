#include "ComplexNumber.h"

// ====== GETTERS ======
double ComplexNumber::getReal() const
{
    return real;
}

double ComplexNumber::getImaginary() const
{
    return imaginary;
}

// ====== OPERATORS ======

ComplexNumber ComplexNumber::operator+(const ComplexNumber& number) const
{
    ComplexNumber result(real + number.real, imaginary + number.imaginary);
    return result;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& number) const
{
    ComplexNumber result(real - number.real, imaginary - number.imaginary);
    return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& number) const
{
    ComplexNumber result((real * number.real) - (imaginary * number.imaginary),
                         (real * number.imaginary) + (imaginary * number.real));
    return result;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& number) const
{
    double denominator = (number.real * number.real) + (number.imaginary * number.imaginary);
    ComplexNumber result((real * number.real + imaginary * number.imaginary) / denominator,
                         (imaginary * number.real - real * number.imaginary) / denominator);
    return result;
}

std::istream& operator>>(std::istream& in, ComplexNumber& number)
{
    in >> number.real >> number.imaginary;
    return in;
}

std::ostream& operator<<(std::ostream& out, ComplexNumber& number)
{
    out << number.real << " + " << number.imaginary << "i";
    return out;
}
    