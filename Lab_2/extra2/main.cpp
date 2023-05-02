#include <iostream>

#include "ComplexNumber.h"

int main()
{
    ComplexNumber num1(2, 3);
    ComplexNumber num2;

    std::cout << "Enter real and imaginary part: ";
    std::cin >> num2;

    ComplexNumber sum = num1 + num2;
    std::cout << num1 << " + " << num2 << " = " << sum << std::endl;

    ComplexNumber diff = num1 - num2;
    std::cout << num1 << " - " << num2 << " = " << diff << std::endl;

    ComplexNumber prod = num1 * num2;
    std::cout << num1 << " * " << num2 << " = " << prod << std::endl;

    ComplexNumber quotient = num1 / num2;
    std::cout << num1 << " / " << num2 << " = " << quotient << std::endl;
    
    return 0;
}