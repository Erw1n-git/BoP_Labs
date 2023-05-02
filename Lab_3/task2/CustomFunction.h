#ifndef CUSTOM_FUNCTION_H
#define CUSTOM_FUNCTION_H

#include <cmath>

#include "Function.h"

class CustomFunction : public Function{
    public:
        virtual double getValue(double x) const;
};

#endif