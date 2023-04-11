#include "Student.h"

const int Student::MAX_GRADES_COUNT = 5;

// ===== CONSTRUCTORS/DESTRUCTOR =====

Student::Student(unsigned int id, const char* surname, const int* grades, size_t n, Group* group)
    : id(id), surname(nullptr), grades(nullptr), group(nullptr)
{
    setSurname(surname);
    setGrades(grades, n);
    setGroup(group);
}

Student::Student(const Student& student)
    : id(student.id), surname(nullptr), grades(nullptr), group(nullptr)
{
    setSurname(student.surname);
    setGrades(student.grades, Student::MAX_GRADES_COUNT);
    setGroup(student.group);
}

Student::~Student()
{
    delete[] surname;
    delete[] grades;
}

// ===== GETTERS =====

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

// ===== SETTERS =====

void Student::setId(unsigned int id)
{
    this->id = id;
}

void Student::setSurname(const char* surname)
{
    if(this->surname != nullptr) delete[] this->surname;
    if (surname != nullptr) 
    {
        this->surname = new char[strlen(surname)+1];
        strcpy(this->surname, surname);
    } 
    else this->surname = nullptr;
}

void Student::setGrades(const int* grades, size_t n)
{
    if(this->grades != nullptr) delete[] this->grades;
    if (grades != nullptr && n > 0) 
    {
        this->grades = new int[n];
        memcpy(this->grades, grades, sizeof(int) * n);
    } 
    else this->grades = nullptr;
}

void Student::setGroup(Group* group)
{
    this->group = group;
}

// ===== OPERATORS =====

const Student& Student::operator=(const Student &student)
{
    if(&student != this)
    {
        setId(student.id);
        setSurname(student.surname);
        setGrades(student.grades, Student::MAX_GRADES_COUNT);
        setGroup(student.group);
    }

    return *this;
}

const bool operator<(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 < sum_student2;
}

const bool operator<=(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 <= sum_student2;
}

const bool operator>(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 > sum_student2;
}

const bool operator>=(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 >= sum_student2;
}

const bool operator==(const Student& student1, const Student& student2)
{
    if (student1.id == student2.id && strcmp(student1.surname, student2.surname) == 0 &&
        memcmp(student1.grades, student2.grades, sizeof(int) * Student::MAX_GRADES_COUNT) == 0 &&
        student1.group == student2.group) return true;

    return false;
}

std::ostream& operator<<(std::ostream& out, Student& student)
{
    out << "ID: " << student.id << ", ";
    out << "Surname: " << student.surname << ", ";
    out << "Grades: ";
    for (int i = 0; i < Student::MAX_GRADES_COUNT; i++)
    {
        out << student.grades[i] << " ";
    }
    out << ", ";
    out << "Group ID: " << student.group->getIndex();
    return out;
}