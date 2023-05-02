#include <iostream>
#include <string.h>

#ifndef HUMAN_CLASSES_H
#define HUMAN_CLASSES_H

class Human{

    private:
        char* name;
        int age;

    public:
        Human(const char* name, int age);
        ~Human();

        char* getName() const;
        int getAge() const;

        void setName(const char* name);
        void setAge(int age);

        virtual void introduce() const;
};

class Citizen : public Human{
    
    private:
        unsigned int socialSecurityNumber;

    public:
        Citizen(const char* name, int age, unsigned int socialSecurityNumber);

        unsigned int getSocialSecurityNumber() const;
        void setSocialSecurityNumber(unsigned int socialSecurityNumber);

        virtual void introduce() const;
};

class Student : public Citizen{

    private:
        char* major;

    public:
        Student(const char* name, int age, unsigned int socialSecurityNumber, const char* major);
        ~Student();

        char* getMajor() const;
        void setMajor(const char* major);

        virtual void introduce() const;
};

class Coworker : public  Citizen{

    private:
        int annualSalary;

    public:
        Coworker(const char* name, int age, unsigned int socialSecurityNumber, int annualSalary);

        int getAnnualSalary() const;
        void setAnnualSalary(int annualSalary);

        virtual void introduce() const;
};

#endif