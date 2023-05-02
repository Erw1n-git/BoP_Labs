#include <iostream>

#include "CustomFunction.h"


int main()
{
    double a,b,h, eps = 0.0000001;

    std::cout << "Enter bounds of interval(a, b) and step(h): " << std::endl;
    std::cin >> a >> b >> h;
    
    CustomFunction func;

    double maxRoot = func.findMaxRoot(a, b, h, eps);

    std::cout << "The second function ( sin(x) + x^2 ): " << std::endl;

    if(maxRoot == b + 1) std::cout << "There are no roots on the given interval!" << std::endl;
    else std::cout << "Max root of the second derivative of the function is: " << maxRoot << std::endl;

    return 0;
}