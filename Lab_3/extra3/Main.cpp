#include <iostream>
#include <vector>

#include "Fraction.h"

template <typename T>
std::vector<T> findElementsInRange(T* arr, size_t size, const T& lower_bound, const T& upper_bound)
{
    std::vector<T> result;
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] >= lower_bound && arr[i] <= upper_bound)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main()
{
    const int n = 5;

    int int_array[] = {1, 5, 8, 2, 4};
    std::vector<int> int_result = findElementsInRange(int_array, n, 4, 8);
    std::cout << "Integers in range [4, 8]: ";
    for (const int& value : int_result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    double double_array[] = {1.5, 3.2, 4.9, 0.6, 3.7};
    std::vector<double> double_result = findElementsInRange(double_array, n, 1.5, 3.7);
    std::cout << "Doubles in range [1.5, 3.7]: ";
    for (const double& value : double_result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    Fraction fraction_array[] = {Fraction(1,2), Fraction(3,4), Fraction(2,3), Fraction(4,5), Fraction(5,6)};
    std::vector<Fraction> fraction_result = findElementsInRange(fraction_array, n, Fraction(1,3), Fraction(2,3));
    std::cout << "Fractions in range [1/3, 2/3]: ";
    for (Fraction& value : fraction_result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}