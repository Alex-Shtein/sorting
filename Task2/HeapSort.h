#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <algorithm>

template <typename T>
void Heapify(T *arr, unsigned size, int root)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != root)
    {
        std::swap(arr[root], arr[largest]);
        Heapify(arr, size, largest);
    }
}

template <typename T>
void HeapSort(T *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

#endif