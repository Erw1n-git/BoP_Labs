#include "main.h"

const int MAX_GRADES_COUNT = 5;

int main(int argc, char **argv)
{
    int grades1[MAX_GRADES_COUNT] = {34, 65, 99, 59};
    int grades2[MAX_GRADES_COUNT] = {50, 92, 43, 12};
    int grades3[MAX_GRADES_COUNT] = {100, 78, 68, 54};

    Student student1(827530, "Luis", grades1, nullptr);

    Student student2;
    student2.setId(340594);
    student2.setSurname("Micah");
    student2.setGrades(grades2);
    student2.setGroup(nullptr);

    Student student3 = student2;
    student3.setSurname("Jamal");
    student3.setGrades(grades3);

    std::cout << "=== [ STUDENT1 INFO ] ===" << std::endl;
    std::cout << student1 << std::endl;

    return 0;
}