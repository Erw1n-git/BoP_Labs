#include "CustomFunction.h"

double CustomFunction::getValue(double x) const
{
    double y = sin(x) + x * x;
    return y;
}