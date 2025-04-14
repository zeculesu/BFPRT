#include <gtest/gtest.h>
#include <vector>
#include <array>

#include "bfprt.h"


TEST(MedianOfMediansTest, SmallArrays) {
    std::vector<int> vec1 = {3};
    EXPECT_EQ(*medianOfMedians(vec1.begin(), vec1.end()), 3);

    std::vector<int> vec2 = {3, 1};
    EXPECT_EQ(*medianOfMedians(vec2.begin(), vec2.end()), 3);

    std::vector<int> vec3 = {5, 2, 9, 1, 7};
    EXPECT_EQ(*medianOfMedians(vec3.begin(), vec3.end()), 5);
}

TEST(MedianOfMediansTest, AllEqual) {
    std::vector<int> vec(25, 42);
    EXPECT_EQ(*medianOfMedians(vec.begin(), vec.end()), 42);
}
