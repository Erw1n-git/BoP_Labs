#include <iostream>
#include <cmath>

struct Point3D
{
    float x;
    float y;
    float z;
};

// Getting the distance between two points
float get_distance(Point3D point_A, Point3D point_B)
{
    float dx = std::pow(point_B.x - point_A.x, 2);
    float dy = std::pow(point_B.y - point_A.y, 2);
    float dz = std::pow(point_B.z - point_A.z, 2);
    float distance = std::sqrt(dx + dy + dz);
    return distance;
}

int main()
{
    Point3D point_A = { 2, 3, 2 };
    Point3D point_B = { 10, -4, 0};

    std::cout << "The distance between two given points is: " << get_distance(point_A, point_B) << std::endl;

    return 0;
}