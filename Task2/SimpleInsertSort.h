#ifndef SIMPLE_INSERT_SORT_H
#define SIMPLE_INSERT_SORT_H

#include <algorithm>

template <typename T>
void SimpleInsertSort(T *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            std::swap(arr[j - 1], arr[j]);
        }
    }
}

#endif
