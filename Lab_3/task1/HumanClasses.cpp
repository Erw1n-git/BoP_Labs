#include "HumanClasses.h"

// ======[ HUMAN ]======

Human::Human(const char* name, int age)
    : name(nullptr)
{
    setName(name);
    setAge(age);
}

Human::~Human()
{
    delete[] name;
}

char* Human::getName() const
{
    return name;
}

int Human::getAge() const
{
    return age;
}

void Human::setName(const char* name)
{
    if(this->name != nullptr) delete[] this->name;
    if(name != nullptr)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    else this->name = nullptr;
}

void Human::setAge(int age)
{
    this->age = age;
}

void Human::introduce() const
{
    std::cout << "Hi, my name is " << getName() << " and I am " << getAge() << " years old." << std::endl;
}

// ======[ CITIZEN ]======

Citizen::Citizen(const char* name, int age, unsigned int socialSecurityNumber)
    : Human(name, age)
{
    this->socialSecurityNumber = socialSecurityNumber; 
}

unsigned int Citizen::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void Citizen::setSocialSecurityNumber(unsigned int socialSecurityNumber)
{
    this->socialSecurityNumber = socialSecurityNumber;
}

void Citizen::introduce() const
{
    std::cout << "Hi, my name is " << getName() << " and I am " << getAge() << " years old." << std::endl;
    std::cout << "My social security number is " << getSocialSecurityNumber() << std::endl;
}

// ======[ STUDENT ]======

Student::Student(const char* name, int age, unsigned int socialSecurityNumber, const char* major)
    : Citizen(name, age,  socialSecurityNumber), major(nullptr)
{
    setMajor(major);
}

Student::~Student()
{
    delete[] major;
}

char* Student::getMajor() const  
{
    return major;
}

void Student::setMajor(const char* major)
{
    if(this->major != nullptr) delete[] this->major;
    if(major != nullptr)
    {
        this->major = new char[strlen(major) + 1];
        strcpy(this->major, major);
    }
    else this->major = nullptr;
}

void Student::introduce() const
{
    std::cout << "Hi, my name is " << getName() << " and I am " << getAge() << " years old." << std::endl;
    std::cout << "My social security number is " << getSocialSecurityNumber() << std::endl;
    std::cout << "My major is " << getMajor() << std::endl;
}

// ======[ COWORKER ]======

Coworker::Coworker(const char* name, int age, unsigned int socialSecurityNumber, int annualSalary)
    : Citizen(name, age, socialSecurityNumber)
{
    setAnnualSalary(annualSalary);
}

int Coworker::getAnnualSalary() const
{
    return annualSalary;
}

void Coworker::setAnnualSalary(int annualSalary)
{
    this->annualSalary = annualSalary;
}

void Coworker::introduce() const
{
    std::cout << "Hi, my name is " << getName() << " and I am " << getAge() << " years old." << std::endl;
    std::cout << "My social security number is " << getSocialSecurityNumber() << std::endl;
    std::cout << "My annual salary is " << getAnnualSalary() << std::endl;
}