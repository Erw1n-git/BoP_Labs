#include "Student.h"

const int MAX_SURNAME_LENGTH = 50;

Student::Student(unsigned int id, const char* surname, const int* grades, Group* group)
{
    setId(id);
    setSurname(surname);
    setGrades(grades);
    setGroup(group);
}

Student::Student(const Student& student)
{
    setId(student.id);
    setSurname(student.surname);
    setGrades(student.grades);
    setGroup(student.group);
}

Student::~Student()
{
    if(surname != nullptr) delete[] surname;
    if(grades != nullptr) delete[] grades;
}

unsigned int Student::getId() const
{
    return id;
}

char* Student::getSurname() const
{
    return surname;
}

int* Student::getGrades() const
{
    return grades;
}

Group* Student::getGroup() const
{
    return group;
}

void Student::setId(unsigned int id)
{
    this->id = id;
}

void Student::setSurname(const char* surname)
{
    if(this->surname != nullptr) delete[] this->surname;
    if (surname != nullptr) 
    {
        this->surname = new char[MAX_SURNAME_LENGTH];
        strcpy(this->surname, surname);
    } 
    else this->surname = nullptr;
}

void Student::setGrades(const int* grades)
{
    if(this->grades != nullptr) delete[] this->grades;
    if (grades != nullptr) 
    {
        this->grades = new int[5];
        memcpy(this->grades, grades, sizeof(int) * 5);
    } 
    else this->grades = nullptr;
}

void Student::setGroup(Group* group)
{
    this->group = group;
}

const Student& Student::operator=(const Student &student)
{
    if(&student != this)
    {
        setId(student.id);
        setSurname(student.surname);
        setGrades(student.grades);
        setGroup(student.group);
    }

    return *this;
}

const bool operator<(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 < sum_student2;
}

const bool operator<=(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 <= sum_student2;
}

const bool operator>(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 > sum_student2;
}

const bool operator>=(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 >= sum_student2;
}

const bool operator==(const Student& student1, const Student& student2)
{
    if (student1.id == student2.id && strcmp(student1.surname, student2.surname) == 0 &&
        memcmp(student1.grades, student2.grades, sizeof(int) * 5) == 0 &&
        student1.group == student2.group) return true;

    return false;
}

std::ostream& operator<<(std::ostream& out, Student& student)
{
    out << "ID: " << student.id << std::endl;
    out << "Surname: " << student.surname << std::endl;
    out << "Grades: ";
    for (int i = 0; i < 5; i++)
    {
        out << student.grades[i] << " ";
    }
    out << "\n";
    out << "Group: " << student.group;
    return out;
}