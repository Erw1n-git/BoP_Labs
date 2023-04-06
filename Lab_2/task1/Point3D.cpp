#include "Point3D.h"

Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point3D::getX()
{
    return this->x;
}

double Point3D::getY()
{
    return this->y;
}

double Point3D::getZ()
{
    return this->z;
}

void Point3D::setX(double x)
{
    this->x = x;
}

void Point3D::setY(double y)
{
    this->y = y;
}

void Point3D::setZ(double z)
{
    this->z = z;
}

double operator-(Point3D p1, Point3D p2)
{
    double dx = std::pow(p2.x - p1.x, 2);
    double dy = std::pow(p2.y - p1.y, 2);
    double dz = std::pow(p2.z - p1.z, 2);
    double distance = std::sqrt(dx + dy + dz);

    return distance;
}