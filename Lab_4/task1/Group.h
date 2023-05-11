#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#ifndef GROUP_H
#define GROUP_H

#define GROUP_CR_SURNAME_ALPHABET 0
#define GROUP_CR_GRADES_SUM 1

class Student;

class Group {

    friend std::ostream& operator<<(std::ostream& out, Group& group);

    private:
        unsigned int index;
        std::vector<Student*> students;

    public:
        static const int MAX_STUDENTS_COUNT = 50;

        Group() : index(0), students() { }
        Group(unsigned int index, std::vector<Student*> students);
        
        unsigned int getIndex() const;
        std::vector<Student*> getStudents() const;

        void setIndex(unsigned int index);
        void setStudents(std::vector<Student*>& students);

        void sortByCriterion(int criterion_id);
        Student* searchById(unsigned int id);
        Student* searchBySurname(std::string surname);

        const Group& operator=(const Group &group);

};

#include "Student.h"

#endif
