#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Task2/RadixSort.h"
#include "../Task2/DutchFlagSort.h"

TEST(RadixSortTest, ReverseSortedArray)
{
    std::string arr[] = {"e", "d", "c", "b", "a"};
    std::string expected[] = {"a", "b", "c", "d", "e"};

    RadixSort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(RadixSortTest, StringArray)
{
    std::string arr[] = {"cat", "dog", "bat", "mat", "hat"};
    std::string expected[] = {"bat", "cat", "dog", "hat", "mat"};

    RadixSort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(RadixSortTest, AlreadySortedArray)
{
    std::string arr[] = {"apple", "banana", "cherry"};
    std::string expected[] = {"apple", "banana", "cherry"};

    RadixSort(arr, 3);

    for (int i = 0; i < 3; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(RadixSortTest, ArrayWithDuplicateValues)
{
    std::string arr[] = {"zebra", "lion", "elephant", "zebra", "lion"};
    std::string expected[] = {"elephant", "lion", "lion", "zebra", "zebra"};

    RadixSort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(RadixSortTest, ArrayWithSpecialCharacters)
{
    std::string arr[] = {"!@", "##", "$$", "%^", "&&"};
    std::string expected[] = {"!@", "##", "$$", "%^", "&&"};

    RadixSort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(RadixSortTest, ArrayWithEmptyStrings)
{
    std::string arr[] = {"", "", "", "", ""};
    std::string expected[] = {"", "", "", "", ""};

    RadixSort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(RadixSortTest, ArrayWithSingleElement)
{
    std::string arr[] = {"only"};
    std::string expected[] = {"only"};

    RadixSort(arr, 1);

    for (int i = 0; i < 1; ++i)
    {
        ASSERT_STREQ(arr[i].c_str(), expected[i].c_str());
        ASSERT_EQ(arr[i], expected[i]);
    }
}
