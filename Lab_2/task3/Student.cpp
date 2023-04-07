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
    id = student.id;
    surname = new char[strlen(student.surname)+1];
    strcpy(surname, student.surname);
    grades = new int[5];
    memcpy(grades, student.grades, sizeof(int) * 5);
    group = student.group;
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
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}

void Student::setGrades(const int* grades)
{
    if(this->grades != nullptr) delete[] this->grades;
    this->grades = new int[5];
    memcpy(this->grades, grades, sizeof(int) * 5);
}

// ! Check on need of deletion of old group
void Student::setGroup(Group* group)
{
    this->group = group;
}

const Student& Student::operator=(Student &student)
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

std::ostream& operator<<(std::ostream& out, Student& student)
{
    
}