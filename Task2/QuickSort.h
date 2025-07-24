#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stack>
#include <algorithm>

template <typename T>
void QuickSort(T *arr, int size)
{
    int low = 0, high = size - 1;
    std::stack<std::pair<int, int>> stk;
    stk.push(std::make_pair(low, high));

    while (!stk.empty())
    {
        low = stk.top().first;
        high = stk.top().second;
        stk.pop();

        int i = low;
        int j = high;
        int pivot = arr[(low + high) / 2];

        while (i <= j)
        {
            while (arr[i] < pivot)
            {
                i++;
            }

            while (arr[j] > pivot)
            {
                j--;
            }

            if (i <= j)
            {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (low < j)
        {
            stk.push(std::make_pair(low, j));
        }

        if (i < high)
        {
            stk.push(std::make_pair(i, high));
        }
    }
}

#endif