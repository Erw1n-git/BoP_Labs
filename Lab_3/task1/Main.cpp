#include <iostream>

#include "HumanClasses.h"

int main(int argc, char* argv[])
{
    Human human("Jack", 13); 
    Citizen citizen("Johny", 15, 10406643);
    Student student("Sergey", 17, 20465402, "Computer Science");
    Coworker coworker("Luis", 25, 46920299, 100000);

    const int n = 4;
    Human* humans[n];
    humans[0] = &human;
    humans[1] = &citizen;
    humans[2] = &student;
    humans[3] = &coworker;
    
    for (int i = 0; i < n; i++)
    {
        humans[i]->introduce();
        std::cout << "\n";
    }
    
    return 0;
}
