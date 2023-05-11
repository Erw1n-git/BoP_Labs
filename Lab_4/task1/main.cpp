#include <iostream>
#include <queue>

#include "Student.h"
#include "Group.h"

struct CompareAverageGrade {
    bool operator()(const Student* a, const Student* b) {
        return a->getAverageGrade() < b->getAverageGrade();
    }
};


int main(int argc, char **argv)
{
    std::vector<int> grades1 = {34, 65, 99, 59, 89};
    std::vector<int> grades2 = {67, 92, 43, 100, 46};
    std::vector<int> grades3 = {100, 78, 68, 54, 88};

    Student student1(827530, "Fernando", grades1, nullptr);
    Student student2;
    student2.setId(512712);
    student2.setSurname("Pascal");
    student2.setGrades(grades2);
    student2.setGroup(nullptr);
    Student student3 = student2;
    student3.setId(675773);
    student3.setSurname("Micah");
    student3.setGrades(grades3);

    std::vector<Student*> students = {&student1, &student2, &student3};
    Group group(1, students);
    group.setStudents(students);

    student1.setGroup(&group);
    student2.setGroup(&group);
    student3.setGroup(&group);

    std::priority_queue<Student*, std::vector<Student*>, CompareAverageGrade> pq;
    pq.push(&student1);
    pq.push(&student2);
    pq.push(&student3);

    std::cout << "Sorting priority_queue by average grade: " << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top()->getSurname() << " (" << pq.top()->getAverageGrade() << ")" << std::endl;
        pq.pop();
    }

    std::cout << "========= [ GROUP LISTING ] =========" << std::endl;
    std::cout << group << std::endl;

    std::cout << "Sort group in alphabetical order:" << std::endl;
    group.sortByCriterion(GROUP_CR_SURNAME_ALPHABET);
    std::cout << "========= [ GROUP LISTING ] =========" << std::endl;
    std::cout << group << std::endl;

    std::cout << "Sort group by grades sum:" << std::endl;
    group.sortByCriterion(GROUP_CR_GRADES_SUM);
    std::cout << "========= [ GROUP LISTING ] =========" << std::endl;
    std::cout << group << std::endl;

    std::cout << "Search for a student with name \'Pascal\'" << std::endl;
    std::cout << *group.searchBySurname("Pascal") << std::endl;

    std::cout << "Search for a student with ID 675773:" << std::endl;
    std::cout << *group.searchById(675773) << std::endl;

    return 0;
}