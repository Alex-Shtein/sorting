#ifndef INSERT_LIST_SORT_H
#define INSERT_LIST_SORT_H

#include <list>

template <typename T>
void InsertListSort(T *arr, int size)
{
    std::list<int> list = {arr[0]};

    for (int i = 1; i < size; ++i)
    {
        auto current = list.begin();
        auto end = list.end();

        while (current != end && *current < arr[i])
        {
            ++current;
        }

        list.insert(current, arr[i]);
    }

    auto current = list.begin();
    auto end = list.end();

    for (int i = 0; i < size && current != end; ++i)
    {
        arr[i] = *current;
        ++current;
    }
}

#endif