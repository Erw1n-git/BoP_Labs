#include <iostream>
#include <string.h>

#ifndef STUDENT_H
#define STUDENT_H 

class Group;

class Student {

    friend std::ostream& operator<<(std::ostream& out, Student& student);
    friend const bool operator<(const Student& student1, const Student& student2);
    friend const bool operator<=(const Student& student1, const Student& student2);
    friend const bool operator>(const Student& student1, const Student& student2);
    friend const bool operator>=(const Student& student1, const Student& student2);
    friend const bool operator==(const Student& student1, const Student& student2);


    private:
        unsigned int id;
        char* surname;
        int* grades;
        Group* group;

    public:
        static const int MAX_GRADES_COUNT;

        Student() : id(0), surname(nullptr), grades(nullptr), group(nullptr) { }
        Student(unsigned int id, const char *surname, const int *grades, size_t n, Group* group);
        Student(const Student& student);
        ~Student();

        unsigned int getId() const;
        char* getSurname() const;
        int* getGrades() const;
        Group* getGroup() const;

        void setId(unsigned int id);
        void setSurname(const char* surname);
        void setGrades(const int* grades, size_t n);
        void setGroup(Group* group); 

        const Student& operator=(const Student &student);

};

#include "Group.h"

#endif