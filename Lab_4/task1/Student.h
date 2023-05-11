#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <numeric>

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
        std::string surname;
        std::vector<int> grades;
        Group* group;

    public:  
        Student() : id(0), surname(""), grades(), group(nullptr) { }
        Student(unsigned int id, std::string surname, std::vector<int> grades, Group* group);
        Student(const Student& student);

        unsigned int getId() const;
        std::string getSurname() const;
        std::vector<int> getGrades() const;
        Group* getGroup() const;
        double getAverageGrade() const;

        void setId(unsigned int id);
        void setSurname(std::string surname);
        void setGrades(std::vector<int>);
        void setGroup(Group* group); 

        const Student& operator=(const Student &student);

};

#include "Group.h"

#endif