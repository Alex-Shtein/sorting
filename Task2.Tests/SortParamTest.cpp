#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Task2/BinaryTreeSort.h"
#include "../Task2/SimpleInsertSort.h"
#include "../Task2/DutchFlagSort.h"
#include "../Task2/HeapSort.h"
#include "../Task2/InsertListSort.h"
#include "../Task2/MergeDownSort.h"
#include "../Task2/MergeUpSort.h"
#include "../Task2/QuickSort.h"
#include "../Task2/RadixSort.h"
#include "../Task2/ShellSort.h"

#include <iostream>

struct paramList
{
    void (*sortFn)(int *arr, int size);
};

class SortParamTest : public ::testing::TestWithParam<struct paramList>
{
protected:
    int ascendingOrder[100000];
    int descendingOrder[100000];
    int randomOrder1[100000];
    int randomOrder2[100000];

    void SetUp() override
    {
        srand(time(NULL));

        for (int i = 0; i < 100000; i++)
        {
            ascendingOrder[i] = i;
            descendingOrder[i] = 100000 - i;
            randomOrder1[i] = rand() % 50;
            randomOrder2[i] = rand() % 1000;
        }
    }

    void TearDown() override {}
};

TEST_P(SortParamTest, Sort)
{
    int size = 100000;
    int copyAscending[size];
    int copyDescending[size];
    int copyRandom1[size];
    int copyRandom2[size];

    for (int i = 0; i < size; i++)
    {
        copyAscending[i] = ascendingOrder[i];
        copyDescending[i] = descendingOrder[i];
        copyRandom1[i] = randomOrder1[i];
        copyRandom2[i] = randomOrder2[i];
    }

    void (*sortFn)(int *, int);
    sortFn = GetParam().sortFn;

    auto start = clock();
    sortFn(copyAscending, size);
    auto finish = clock();
    auto time = finish - start;
    ASSERT_TRUE(std::is_sorted(copyAscending, copyAscending + size));
    std::cout << "Test with right sequence passed in " << time / 1000 << std::endl;

    start = clock();
    sortFn(copyDescending, size);
    finish = clock();
    time = finish - start;
    ASSERT_TRUE(std::is_sorted(copyAscending, copyAscending + size));
    std::cout << "Test with wrong sequence passed by " << time / 1000 << std::endl;

    start = clock();
    sortFn(copyRandom1, size);
    finish = clock();
    time = finish - start;
    ASSERT_TRUE(std::is_sorted(copyAscending, copyAscending + size));
    std::cout << "Test with sequence with often repeats passed by " << time / 1000 << std::endl;

    start = clock();
    sortFn(copyRandom2, size);
    finish = clock();
    time = finish - start;
    ASSERT_TRUE(std::is_sorted(copyAscending, copyAscending + size));
    std::cout << "Test with sequence with seldom repeats passed by " << time / 1000 << std::endl;
};

INSTANTIATE_TEST_CASE_P(
    SortParamTest,
    SortParamTest,
    ::testing::Values(
        // paramList{BinaryTreeSort},
        paramList{DutchFlagSort}
        // paramList{HeapSort},
        // paramList{InsertListSort},
        // paramList{MergeDownSort},
        // paramList{MergeUpSort},
        // paramList{QuickSort},
        // paramList{ShellSort},
        // paramList{SimpleInsertSort}
        ));
