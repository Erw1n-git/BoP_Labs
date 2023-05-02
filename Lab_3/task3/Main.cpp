#include <iostream>

#include "MaxRootTemplate.h"
#include "FunctionObject.h"

double function1(double x)
{
    double y = pow(x, 3) + 2 * x;
    return y;
}

int main(int argc, char** argv)
{ 
    double a,b,h, eps = 0.0000001;

    std::cout << "Enter bounds of interval(a, b) and step(h): " << std::endl;
    std::cin >> a >> b >> h;
    
    std::cout << "The first function ( x^3 + 2x ): " << std::endl;
    printMaxRoot(function1, a, b, h, eps);

    FunctionObject function2;
    std::cout << "The second function ( sin(x) + x^2 ): " << std::endl;
    printMaxRoot(function2, a, b, h, eps);

    return 0;
}