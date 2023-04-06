#include <iostream>
#include <string.h>

const int GRADES_COUNT = 4;
const int SURNAME_LENGTH = 20;

struct Student
{
    unsigned int studentID;
    char surname[SURNAME_LENGTH];
    int grades[GRADES_COUNT];
    
    public:
        static void printStudentInfo(Student &s)
        {
            std::cout << "Student ID: " << s.studentID;
            std::cout << " Surname: " << s.surname;
            std::cout << " Grades: "; 
            
            for(int i = 0; i < GRADES_COUNT; i++)
            {
                if(i < GRADES_COUNT-1) std::cout << s.grades[i] << ", ";
                else std::cout << s.grades[i] << ".";
            }

            std::cout << "\n";
        }
};

// Printing information about student

// Print information about all students
void printStudentsInfo(Student **students, int size)
{
    for (int i = 0; i < size; i++)
    {
        Student::printStudentInfo(*students[i]);
    }
    
}

// Sorting students by surname in alphabetical order
void sortInAlphabetOrder(Student **students, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(strcmp(students[i]->surname, students[j]->surname) > 0)
            {
                std::swap(students[i], students[j]);
            }
        }
    }
    
}

// Searching students with even grades sum
void searchStudentsWithEvenSum(Student **students, int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < GRADES_COUNT; j++) {
            sum += students[i]->grades[j];
        }

        if (sum % 2 == 0) {
            Student::printStudentInfo(*students[i]);
        }
    }
}

int main()
{
    const int n = 5;

    Student students[n] = { 
        { 637032551, "Budanov", {99, 75, 84, 91} },
        { 892448323, "Podolyak", {80, 79, 94, 82} },
        { 258523062, "Ermak", {68, 71, 73, 90}, },
        { 438560372, "Zaluzhniy", {100, 95, 99, 94} },
        { 763296356, "Kuleba", {69, 65, 77, 73} }
    };
    
    // Filling the pointers array 
    Student *pStudents[n];
    for (int i = 0; i < n; i++)
    {
        pStudents[i] = &students[i];
    }
    
    printStudentsInfo(pStudents, n);

    std::cout << "\nSorting students in alphabetical order..." << std::endl;
    sortInAlphabetOrder(pStudents, n);
    printStudentsInfo(pStudents, n);

    std::cout << "\nStudents with even sum of grades: " << std::endl;
    searchStudentsWithEvenSum(pStudents, n);

    return 0;
}