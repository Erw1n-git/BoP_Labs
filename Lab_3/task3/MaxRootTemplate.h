#ifndef MAXROOT_TEMPLATE_H
#define MAXROOT_TEMPLATE_H

#include <iostream>
#include <cmath>

template <typename Func>
double firstDerivative(const Func f, double x, double eps)
{
    return (f(x + eps) - f(x)) / eps;
}

template <typename Func>
double secondDerivative(const Func f, double x, double eps)
{
    double y1 = firstDerivative(f, x, eps);
    double y2 = firstDerivative(f, x + eps, eps);
    return (y2 - y1) / eps;
}

template <typename Func>
void printMaxRoot(const Func f, double a, double b, double h, double eps)
{
    double max = b + 1;

    for(int i = a; i <= b; i+= h)
    {
        if(secondDerivative(f, i, eps) == 0) max = i;
    }

     if (max == b + 1) std::cout << "There are no roots on the given interval!" << std::endl;
    else std::cout << "Max root of the second derivative of the function is: " << max << std::endl;
}

#endif