#include <iostream>
#include "ArrayFunctions.h"
#include "Fraction.h"


template <typename T>
void printArray(T *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const int n = 5;
    int int_array[] = {3, 5, 1, 9, 2};
    printArray(int_array, n);

    swapElements(int_array, 1, 3);
    printArray(int_array, n);

    int int_search = 9;
    int int_index = findElement(int_array, n, int_search);
    std::cout << "Index of element " << int_search << ": " << int_index << std::endl;

    swapAdjacentElements(int_array, n);
    printArray(int_array, n);

    double double_array[] = {1.5, 4.2, 0.6, 3.7, 2.3};
    printArray(double_array, n);

    swapElements(double_array, 0, 2);
    printArray(double_array, n);

    double double_search = 4.2;
    int double_index = findElement(double_array, n, double_search);
    std::cout << "Index of element " << double_search << ": " << double_index << std::endl;

    swapAdjacentElements(double_array, n);
    printArray(double_array, n);

    Fraction fraction_array[] = {Fraction(1, 2), Fraction(8, 10), Fraction(3, 4), Fraction(32, 454), Fraction(35, 94)};
    printArray(fraction_array, n);

    swapElements(fraction_array, 0, 3);
    printArray(fraction_array, n);

    Fraction fraction_search(8, 10);
    int fraction_index = findElement(fraction_array, n, fraction_search);
    std::cout << "Index of element " << fraction_search << ": " << fraction_index << std::endl;

    swapAdjacentElements(fraction_array, n);
    printArray(fraction_array, n);

    return 0;
}