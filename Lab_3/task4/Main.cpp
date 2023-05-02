#include <iostream>
#include <vector>

#include "MatrixTemplate.h"
#include "Fraction.h"

template <typename T>
T findMinElement(const std::vector<T> &arr)
{
    if (arr.empty())
    {
        throw std::invalid_argument("This array is empty.");
    }
    
    T min_element = arr[0];
    for (const T& element: arr)
    {
        if (element < min_element)
        {
            min_element = element;
        }
    }

    return min_element;
}

int main(int argc, char* argv[])
{
    std::vector<int> int_array = {3, 5, 1, 9, 2};
    int min_int = findMinElement(int_array);
    std::cout << "Min int element: " << min_int << std::endl;

    std::vector<double> double_array = {1.5, 4.2, 0.6, 3.7};
    double min_double = findMinElement(double_array);
    std::cout << "Min double element: " << min_double << std::endl;

    std::vector<Fraction> fraction_array = { Fraction(1,2), Fraction(8, 10), Fraction(3, 4), Fraction(32, 454) };
    Fraction min_fraction = findMinElement(fraction_array);
    std::cout << "Min fraction element: " << min_fraction << std::endl;

    return 0;
}