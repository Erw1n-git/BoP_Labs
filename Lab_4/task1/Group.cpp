#include "Group.h"

// ===== CONSTRUCTORS/DESTRUCTOR =====

Group::Group(unsigned int index, std::vector<Student*> students)
    : index(index), students()
{
    this->students = students;
}

// ===== GETTERS =====

unsigned int Group::getIndex() const
{
    return index;
}

std::vector<Student*> Group::getStudents() const
{
    return students;
}

// ===== SETTERS =====

void Group::setIndex(unsigned int index)
{
    this->index = index;
}

void Group::setStudents(std::vector<Student*>& students) {
    this->students.clear();
    for (auto student : students) {
        this->students.push_back(student);
    }
}

// ===== OPERATORS =====

std::ostream& operator<<(std::ostream& out, Group& group)
{
    out << "Group's ID: " << group.index << std::endl;
    for (size_t i = 0; i < group.students.size(); i++)
    {
        out << *group.students[i] << "\n";
    }
    return out;
}

const Group& Group::operator=(const Group &group)
{
    if(&group != this)
    {
        this->index = group.index;
        this->students = group.students;
    }
    return *this;
}

// ===== OTHERS =====

bool compareBySurname(Student* student1, Student* student2)
{
    return student1->getSurname() == student2->getSurname();
}

bool compareByGrades(Student* student1, Student* student2)
{
    return student1 > student2;
}

void Group::sortByCriterion(int criterion_id)
{
    switch (criterion_id)
    {
    case GROUP_CR_SURNAME_ALPHABET:
        std::sort(students.begin(), students.end(), compareBySurname);
        break;
    
    case GROUP_CR_GRADES_SUM:
        std::sort(students.begin(), students.end(), compareByGrades);
        break;
    default:
        break;
    }
}

Student* Group::searchById(unsigned int id)
{
    Student* foundStudent = nullptr;

    std::for_each(students.begin(), students.end(), [&foundStudent, id](Student* student) {
        if (student->getId() == id) {
            foundStudent = student;
        }
    });

    return foundStudent;
}

Student* Group::searchBySurname(std::string surname)
{
    Student* foundStudent = nullptr;

    std::for_each(students.begin(), students.end(), [&foundStudent, &surname](Student* student) {
        if (student->getSurname() == surname) {
            foundStudent = student;
        }
    });

    return foundStudent;
}

