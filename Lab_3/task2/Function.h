#ifndef FUNCTION_H
#define FUNCTION_H

class Function{
    public: 
        virtual double getValue(double x) const = 0;
        double firstDerivative(double x, double eps) const;
        double secondDerivative(double x, double eps) const;
        double findMaxRoot(double a, double b, double h, double eps) const;
};

#endif