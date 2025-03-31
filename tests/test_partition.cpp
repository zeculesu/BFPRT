#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <list>
#include <string>
#include "bfprt.h"

#include <algorithm>


TEST(PartitionTest, GroupsCorrectlyPartitioned) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    auto pivotIt = v.begin() + 2; // = 4
    auto n = 3;

    auto boundary = partition(v.begin(), v.end() - 1, pivotIt, n);

    for (auto it = v.begin(); it != boundary; ++it) {
        ASSERT_LT(*it, 4);
    }

    auto eqStart = boundary;
    while (eqStart != v.end() && *eqStart == 4) ++eqStart;
    for (auto it = boundary; it != eqStart; ++it) {
        ASSERT_EQ(*it, 4);
    }

    for (auto it = eqStart; it != v.end(); ++it) {
        ASSERT_GT(*it, 4);
    }
}

TEST(PartitionTest, ReturnValueDependsOnN) {
    std::vector<int> v = {0, 2, 6, 3, 5, 1, 1};
    auto pivotIt = v.begin() + 3; // = 3
    
    auto boundary1 = partition(v.begin(), v.end() - 1, pivotIt, 1);
    EXPECT_EQ(boundary1 - v.begin(), 4);
}

TEST(PartitionTest, NOutOfBounds) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    auto pivotIndex = v.begin() + 2;

    auto boundary = partition(v.begin(), v.end() - 1, pivotIndex, 10);
    std::cout << "Boundary position: " << (boundary - v.begin()) << "\n";

    EXPECT_EQ(boundary - v.begin(), 4);
}

TEST(PartitionTest, AllElementsEqual) {
    std::vector<int> v = {2, 2, 2, 2, 2};
    auto pivotIt = v.begin() + 1;
    auto n = 2;

    auto boundary = partition(v.begin(), v.end() - 1, pivotIt, n);

    EXPECT_EQ(boundary, v.begin() + n);
}

TEST(PartitionTest, EmptyRange) {
    std::vector<int> v;
    auto boundary = partition(v.begin(), v.end(), v.begin(), 0);
    EXPECT_EQ(boundary, v.begin());
}
