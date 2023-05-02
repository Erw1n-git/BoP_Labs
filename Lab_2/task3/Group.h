#include <algorithm>
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
        Student** students;
        unsigned int size;

    public:
        static const int MAX_STUDENTS_COUNT = 50;

        Group() : index(0), students(nullptr), size(0) { }
        Group(unsigned int index, Student** students, unsigned int size);
        ~Group();
        
        unsigned int getIndex() const;
        Student** getStudents() const;
        unsigned int getSize() const;

        void setIndex(unsigned int index);
        void setStudents(Student** students);
        void setSize(unsigned int size);

        void sortByCriterion(int criterion_id);
        Student* searchById(unsigned int id);
        Student* searchBySurname(const char* surname);

        const Group& operator=(const Group &group);

};

#include "Student.h"

#endif
