#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iterator>

template <typename T>
void RadixSort(T *data, int size)
{
    int wordLength = data[0].size();
    int radix = 256;
    std::string *auxArray = new std::string[size];
    int *countArray = new int[radix];

    for (int k = wordLength - 1; k >= 0; k--)
    {
        for (int i = 0; i < radix; i++)
        {
            countArray[i] = 0;
        }

        for (int i = 0; i < size; i++)
        {
            countArray[data[i][k] + 1]++;
        }

        for (int i = 0; i < radix; i++)
        {
            countArray[i + 1] += countArray[i];
        }

        for (int i = 0; i < size; i++)
        {
            auxArray[countArray[data[i][k]]++] = data[i];
        }

        for (int i = 0; i < size; i++)
        {
            data[i] = auxArray[i];
        }
    }

    delete[] auxArray;
    auxArray = nullptr;
    delete[] countArray;
    countArray = nullptr;
}

#endif