#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "bfprt.h"


TEST(MedianOfMedianTest, OddSizeVector) {
    std::vector<int> v = {5, 3, 1, 4, 2}; 
    auto result = median_of_median(v.begin(), v.end() - 1);
    std::sort(v.begin(), v.end());
    int expected = v[v.size()/2];
    EXPECT_EQ(result, expected);
}

TEST(MedianOfMedianTest, OddSizeArray) {
    std::array<int, 5> v = {5, 3, 1, 4, 2}; 
    auto result = median_of_median(v.begin(), v.end() - 1);
    std::sort(v.begin(), v.end());
    int expected = v[v.size()/2];
    EXPECT_EQ(result, expected);
}

TEST(MedianOfMedianTest, EvenSizeArray) {
    std::vector<double> v = {5, 3, 1, 4, 2, 6};
    // 1 2 3 4 5 6 
    auto result = median_of_median(v.begin(), v.end() - 1);
    std::sort(v.begin(), v.end());
    double expected = 0.5 * (v[v.size()/2 - 1] + v[v.size()/2]);
    EXPECT_DOUBLE_EQ(result, expected);
}

TEST(MedianOfMedianTest, SmallArrays) {
    std::vector<int> v1 = {5};
    EXPECT_EQ(median_of_median(v1.begin(), v1.end() - 1), 5);

    std::vector<int> v2 = {3, 1};
    EXPECT_DOUBLE_EQ(median_of_median(v2.begin(), v2.end() - 1), 2.0);
}