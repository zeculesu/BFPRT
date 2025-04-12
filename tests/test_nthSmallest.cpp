#include "bfprt.h"
#include <vector>
#include <gtest/gtest.h>

TEST(NthSmallestTest, SortedArray) {
    std::vector<int> arr{1, 2, 3, 4, 5};
    int val = nthSmallest(arr.begin(), arr.end(), 2);

    arr = {1, 2, 3, 4, 5};

    std::nth_element(arr.begin(), arr.begin() + 2, arr.end());

    int referens = arr[2];

    EXPECT_EQ(val, referens);
}

TEST(NthSmallestTest, ReverseSortedArray) {
    std::vector<int> arr{5, 4, 3, 2, 1};
    int val = nthSmallest(arr.begin(), arr.end(), 0);
    EXPECT_EQ(val, 1);
}

TEST(NthSmallestTest, RandomOrder) {
    std::vector<int> arr{10, 3, 5, 1, 8};
    int val = nthSmallest(arr.begin(), arr.end(), 3);
    EXPECT_EQ(val, 8);
}

TEST(NthSmallestTest, DuplicateElements) {
    std::vector<int> arr{4, 2, 2, 2, 6};
    int val = nthSmallest(arr.begin(), arr.end(), 2);
    EXPECT_EQ(val, 2);
}

TEST(NthSmallestTest, SingleElement) {
    std::vector<int> arr{42};
    int val = nthSmallest(arr.begin(), arr.end(), 0);
    EXPECT_EQ(val, 42);
}

TEST(NthSmallestTest, EmptyVector) {
    std::vector<int> arr{};
    EXPECT_THROW(nthSmallest(arr.begin(), arr.end(), 0), std::out_of_range);
}

TEST(NthSmallestTest, OutOfRangeIndex) {
    std::vector<int> arr{1, 2, 3};
    EXPECT_THROW(nthSmallest(arr.begin(), arr.end(), 5), std::out_of_range);
}
