#ifndef DUTCH_FLAG_SORT_H
#define DUTCH_FLAG_SORT_H

#include <algorithm>
#include <vector>

template <typename T>
std::pair<T, T> partition(T *arr, int start, int end)
{
    int mid = start;
    int pivot = arr[end];

    while (mid <= end)
    {
        if (arr[mid] < pivot)
        {
            std::swap(arr[start], arr[mid]);
            ++start, ++mid;
        }

        else if (arr[mid] > pivot)
        {
            std::swap(arr[mid], arr[end]);
            --end;
        }
        else
        {
            ++mid;
        }
    }

    return std::make_pair(start - 1, mid);
}

template <typename T>
void quicksort(T *nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    std::pair<T, T> pivot = partition(nums, start, end);
    quicksort(nums, start, pivot.first);
    quicksort(nums, pivot.second, end);
}

template <typename T>
void DutchFlagSort(T *nums, int size)
{
    quicksort(nums, 0, size - 1);
}

#endif