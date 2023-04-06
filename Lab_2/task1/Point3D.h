#include <cmath>

#ifndef Point3D_H
#define Point3D_H

class Point3D {

    friend double operator-(Point3D, Point3D);

    private:
        double x;
        double y;
        double z;

    public:
        Point3D() :  Point3D(0, 0, 0) {}
        Point3D(double x, double y, double z);

        double getX();
        double getY();
        double getZ();

        void setX(double x);
        void setY(double y);
        void setZ(double z);

};



#endif