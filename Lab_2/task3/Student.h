#include <iostream>
#include <string.h>

#ifndef STUDENT_H
#define STUDENT_H 

class Group;

class Student {

    friend std::ostream& operator<<(std::ostream& out, Student& student);

    private:
        unsigned int id;
        char* surname;
        int* grades;
        Group* group;

    public:
        Student() : Student(0, nullptr, nullptr, nullptr) { }
        Student(unsigned int id, const char *surname, const int *grades, Group *group);
        Student(const Student& student);
        ~Student();

        unsigned int getId() const;
        char* getSurname() const;
        int* getGrades() const;
        Group* getGroup() const;

        void setId(unsigned int id);
        void setSurname(const char* surname);
        void setGrades(const int* grades);
        void setGroup(Group* group); 

        const Student& operator=(Student &student);

};

#include "Group.h"

#endif