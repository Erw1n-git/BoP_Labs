#include "Group.h"

const int Group::MAX_STUDENTS_COUNT = 50;

// ===== CONSTRUCTORS/DESTRUCTOR =====

Group::Group(unsigned int index, Student** students, unsigned int size)
    : index(index), students(nullptr), size(size)
{
    setStudents(students);
}

Group::~Group()
{
    for (size_t i = 0; i < size; i++)
    {
        delete students[i];
    }
    
    delete[] students;
}

// ===== GETTERS =====

unsigned int Group::getIndex() const
{
    return index;
}

Student** Group::getStudents() const
{
    return students;
}

unsigned int Group::getSize() const
{
    return size;
}

// ===== SETTERS =====

void Group::setIndex(unsigned int index)
{
    this->index = index;
}

void Group::setStudents(Student** students)
{
    if(students != nullptr) 
    {
        if(this->students != nullptr)
        {
            for(size_t i = 0; i < size; i++)
            {
                delete this->students[i];
            }
            delete[] this->students;
        }

        this->students = new Student*[size];
        for (size_t i = 0; i < size; i++)
        {
            this->students[i] = new Student(*students[i]);
        }
    } 
    else this->students = nullptr; 
}

void Group::setSize(unsigned int size)
{
    this->size = size;
}

// ===== OPERATORS =====

std::ostream& operator<<(std::ostream& out, Group& group)
{
    out << "Group's ID: " << group.index << std::endl;
    for (size_t i = 0; i < group.size; i++)
    {
        out << *group.students[i] << "\n";
    }
    return out;
}

const Group& Group::operator=(const Group &group)
{
    if(&group != this)
    {
        setIndex(group.index);
        setStudents(group.students);
        setSize(group.size);
    }
    return *this;
}

// ===== OTHERS =====

bool compareBySurname(Student* student1, Student* student2)
{
    return strcmp(student1->getSurname(), student2->getSurname()) < 0;
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
        std::sort(students, students + size, compareBySurname);
        break;
    
    case GROUP_CR_GRADES_SUM:
        std::sort(students, students + size, compareByGrades);
        break;
    default:
        break;
    }
}

Student* Group::searchById(unsigned int id)
{
    for (size_t i = 0; i < size; i++)
    {
        if(students[i]->getId() == id) return students[i];
    }
    return nullptr;
}

Student* Group::searchBySurname(const char* surname)
{
    for (size_t i = 0; i < size; i++)
    {
        if(strcmp(students[i]->getSurname(), surname) == 0) return students[i];
    }
    return nullptr;
}
