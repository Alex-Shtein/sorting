#ifndef MERGE_UP_SORT_H
#define MERGE_UP_SORT_H

template <typename T>
T *Merge(T *m1, T *m2, int l1, int l2)
{
    T *res = new T[l1 + l2];
    int n = 0;

    while (l1 && l2)
    {
        if (*m1 < *m2)
        {
            res[n] = *m1;
            m1++;
            --l1;
        }

        else
        {
            res[n] = *m2;
            ++m2;
            --l2;
        }
        ++n;
    }

    if (l1 == 0)
    {
        for (int i = 0; i < l2; ++i)
        {
            res[n++] = *m2++;
        }
    }

    else
    {
        for (int i = 0; i < l1; ++i)
        {
            res[n++] = *m1++;
        }
    }
    return res;
}

template <typename T>
void MergeUpSort(T *arr, int size)
{
    int n = 1, l, ost;
    T *mas1;
    while (n < size)
    {
        l = 0;
        while (l < size)
        {
            if (l + n >= size)
                break;
            ost = (l + n * 2 > size) ? (size - (l + n)) : n;
            mas1 = Merge(arr + l, arr + l + n, n, ost);
            for (int i = 0; i < n + ost; ++i)
                arr[l + i] = mas1[i];
            delete[] mas1;
            l += n * 2;
        }
        n *= 2;
    }
}

#endif

// O(n * log(n))
// {7} {6} {4} {3} {9} {2} {1} {5} {8} {10}
// {6, 7} {3, 4} {2, 9} {1, 5} {8, 10}
// {3, 4, 6, 7} {1, 2, 5, 9} {8, 10}
// {1, 2, 3, 4, 5, 6, 7, 9} {8, 10}
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}