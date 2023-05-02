#include <iostream>

#include "Student.h"
#include "Group.h"

int main(int argc, char **argv)
{
    int grades1[Student::MAX_GRADES_COUNT] = {34, 65, 99, 59, 89};
    int grades2[Student::MAX_GRADES_COUNT] = {67, 92, 43, 100, 46};
    int grades3[Student::MAX_GRADES_COUNT] = {100, 78, 68, 54, 88};

    Group group(1, nullptr, 3);
    Student student1(827530, "Fernando", grades1, 5, &group);
    Student student2;
    student2.setId(512712);
    student2.setSurname("Pascal");
    student2.setGrades(grades2, Student::MAX_GRADES_COUNT);
    student2.setGroup(&group);
    Student student3 = student2;
    student3.setId(675773);
    student3.setSurname("Micah");
    student3.setGrades(grades3, Student::MAX_GRADES_COUNT);

    Student* students[] = {&student1, &student2, &student3};
    group.setStudents(students);

    std::cout << "========= [ GROUP LISTING ] =========" << std::endl;
    std::cout << group << std::endl;

    std::cout << "\nSort group in alphabetical order:\n" << std::endl;
    group.sortByCriterion(GROUP_CR_SURNAME_ALPHABET);
    std::cout << "========= [ GROUP LISTING ] =========" << std::endl;
    std::cout << group << std::endl;

    std::cout << "\nSort group by grades sum:\n" << std::endl;
    group.sortByCriterion(GROUP_CR_GRADES_SUM);
    std::cout << "========= [ GROUP LISTING ] =========" << std::endl;
    std::cout << group << std::endl;

    std::cout << "\nSearch for a student with name \'Pascal\'" << std::endl;
    std::cout << *group.searchBySurname("Pascal") << std::endl;

    std::cout << "\nSearch for a student with ID 675773:" << std::endl;
    std::cout << *group.searchById(675773) << std::endl;

    return 0;
}