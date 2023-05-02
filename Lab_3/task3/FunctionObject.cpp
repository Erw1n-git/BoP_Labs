#include "FunctionObject.h"
#include <cmath>

double FunctionObject::operator()(double x) const
{
    double y = sin(x) + x * x;
    return y;
}