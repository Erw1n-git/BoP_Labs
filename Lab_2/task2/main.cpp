#include "main.h"

int main(int argc, char **argv)
{
    Fraction f1, f2, f3;
    bool comp;

    while(1)
    {
        std::cout << "Enter two fractions ( n/d ):" << std::endl;
        std::cin >> f1;
        std::cin >> f2;
    
        if(std::cin.fail())
        {
            std::cout << "Please enter fraction in a valid format!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            continue;
        }
        break;
    }
    

    std::cout << "\nReducing fractions if possible..." << std::endl;
    f1.reduce();
    f2.reduce();
    std::cout << "F1: " << f1 << std::endl;
    std::cout << "F2: " << f2 << std::endl;

    f3 = f1 + f2;
    std::cout << "\nF1 + F2: " << f3 << std::endl;
    
    f3 = f1 - f2;
    std::cout << "F1 - F2: " << f3 << std::endl;

    f3 = f1 * f2;
    std::cout << "F1 * F2: " << f3 << std::endl;

    f3 = f1 / f2;
    std::cout << "F1 / F2: " << f3 << std::endl;

    comp = f1 < f2;
    std::cout << "F1 < F2: " << comp << std::endl;

    comp = f1 <= f2;
    std::cout << "F1 <= F2: " << comp << std::endl;

    comp = f1 > f2;
    std::cout << "F1 > F2: " << comp << std::endl; 

    comp = f1 >= f2;
    std::cout << "F1 >= F2: " << comp << std::endl;
    return 0;
}