#ifndef MERGE_DOWN_SORT_H
#define MERGE_DOWN_SORT_H

template <typename T>
void Merge(T *arr, int left, int right)
{
    if (left == right)
    {
        return;
    }

    int middle = (left + right) / 2;
    Merge(arr, left, middle);
    Merge(arr, middle + 1, right);
    int i = left, j = middle + 1;
    int *temp = new int[right - left + 1];

    for (int step = 0; step < right - left + 1; step++)
    {
        if ((j > right) || ((i <= middle) && (arr[i] < arr[j])))
        {
            temp[step] = arr[i];
            i++;
        }

        else
        {
            temp[step] = arr[j];
            j++;
        }
    }

    for (int step = 0; step < right - left + 1; step++)
    {
        arr[left + step] = temp[step];
    }

    free(temp);
}

template <typename T>
void MergeDownSort(T *arr, int size)
{
    Merge(arr, 0, size - 1);
}

#endif

// O(n * log(n))
// {7} {6} {4} {3} {9} {2} {1} {5} {8} {10}
// {6, 7} {3, 4} {2, 9} {1, 5} {8, 10}
// {3, 4, 6, 7} {1, 2, 5, 9} {8, 10}
// {1, 2, 3, 4, 5, 6, 7, 9} {8, 10}
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}