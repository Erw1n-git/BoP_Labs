#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <algorithm>

template <typename T>
void swapElements(T *arr, size_t i, size_t j)
{
    std::swap(arr[i], arr[j]);
}

template <typename T>
int findElement(T *arr, size_t size, T &value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    
    return -1;
}

template <typename T>
void swapAdjacentElements(T *arr, size_t size)
{
    for (size_t i = 1; i < size; i += 2)
    {
        std::swap(arr[i], arr[i - 1]);
    }
    
}

#endif