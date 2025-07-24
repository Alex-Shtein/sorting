#ifndef SHELL_SORT_H
#define SHELL_SORT_H

template <typename T>
void ShellSort(T *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            T temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

#endif