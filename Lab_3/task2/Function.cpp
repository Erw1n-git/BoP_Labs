#include "Function.h"

double Function::firstDerivative(double x, double eps) const
{
    return (getValue(x + eps) - getValue(x)) / eps;
}

double Function::secondDerivative(double x, double eps) const
{
    double y1 = firstDerivative(x, eps);
    double y2 = firstDerivative(x + eps, eps);
    return (y2 - y1) / eps;
}

double Function::findMaxRoot(double a, double b, double h, double eps) const
{
    double max = b + 1;

    for(int i = a; i <= b; i+= h)
    {
        if(secondDerivative(i, eps) == 0) max = i;
    }

    return max;
}