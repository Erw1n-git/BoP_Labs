#include "Student.h"

// ===== CONSTRUCTORS/DESTRUCTOR =====

Student::Student(unsigned int id, std::string surname, std::vector<int> grades, Group* group)
    : id(id), surname(""), grades(), group(nullptr)
{
    this->surname = surname;
    this->grades = grades;
    this->group = group;
}

Student::Student(const Student& student)
    : id(student.id), surname(""), grades(), group(nullptr)
{
    this->surname = surname;
    this->grades = grades;
    this->group = group;
}

// ===== GETTERS =====

unsigned int Student::getId() const
{
    return id;
}

std::string Student::getSurname() const
{
    return surname;
}

std::vector<int> Student::getGrades() const
{
    return grades;
}

Group* Student::getGroup() const
{
    return group;
}

double Student::getAverageGrade() const
{
    if (grades.empty()) {
        return 0;
    }
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

// ===== SETTERS =====

void Student::setId(unsigned int id)
{
    this->id = id;
}

void Student::setSurname(std::string surname)
{
    this->surname = surname;
}

void Student::setGrades(std::vector<int> grades)
{
    this->grades = grades;
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
        this->id = student.id;
        this->surname = student.surname;
        this->grades = student.grades;
        this->group = group;
    }

    return *this;
}

const bool operator<(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (size_t i = 0; i < student1.grades.size(); i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (size_t i = 0; i < student2.grades.size(); i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 < sum_student2;
}

const bool operator<=(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (size_t i = 0; i < student1.grades.size(); i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (size_t i = 0; i < student2.grades.size(); i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 <= sum_student2;
}

const bool operator>(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (size_t i = 0; i < student1.grades.size(); i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (size_t i = 0; i < student2.grades.size(); i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 > sum_student2;
}

const bool operator>=(const Student& student1, const Student& student2)
{
    int sum_student1 = 0;
    for (size_t i = 0; i < student1.grades.size(); i++) 
    {
        sum_student1 += student1.grades[i];
    }

    int sum_student2 = 0;
    for (size_t i = 0; i < student2.grades.size(); i++) 
    {
        sum_student2 += student2.grades[i];
    }

    return sum_student1 >= sum_student2;
}

const bool operator==(const Student& student1, const Student& student2)
{
    if (student1.id == student2.id && 
        student1.surname == student2.surname &&
        student1.grades == student2.grades &&
        student1.group == student2.group) return true;

    return false;
}

std::ostream& operator<<(std::ostream& out, Student& student)
{
    out << "ID: " << student.id << ", ";
    out << "Surname: " << student.surname << ", ";
    out << "Grades: ";
    for (size_t i = 0; i < student.grades.size(); i++)
    {
        out << student.grades[i] << " ";
    }
    out << ", ";
    out << "Group ID: " << student.group->getIndex();
    return out;
}