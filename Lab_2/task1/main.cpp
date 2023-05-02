#include <iostream>
#include "Point3D.h"

int main(int argc, char **argv)
{
    Point3D pointA(2, 4, 3.5);

    Point3D pointB;
    pointB.setX(17);
    pointB.setY(-6.2);
    pointB.setZ(2);

    std::cout << "Distance between PointA and PointB: " << pointA - pointB << std::endl;

    pointA.setX(14);
    pointA.setY(-3.52);
    pointA.setZ(5.02);

    std::cout << "Distance between PointA and PointB: " << operator-(pointA, pointB) << std::endl;

    return 0;
}