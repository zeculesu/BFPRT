#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

#include "bfprt.h"

TEST(ExceptionTest, EmptyRange) {
    std::vector<int> emptyVec;
    EXPECT_THROW({
        bfprt(emptyVec.begin(), emptyVec.end(), 1);
    }, std::invalid_argument);
}

TEST(ExceptionTest, KTooSmall) {
    std::vector<int> vec = {1, 2, 3};
    EXPECT_THROW({
        bfprt(vec.begin(), vec.end(), 0);
    }, std::out_of_range);
}

TEST(ExceptionTest, KTooLarge) {
    std::vector<int> vec = {1, 2, 3};
    EXPECT_THROW({
        bfprt(vec.begin(), vec.end(), 4);
    }, std::out_of_range);
}

TEST(ExceptionTest, NegativeK) {
    std::vector<int> vec = {1, 2, 3};
    EXPECT_THROW({
        bfprt(vec.begin(), vec.end(), -1);
    }, std::out_of_range);
}

TEST(ExceptionTest, SingleElementValidK) {
    std::vector<int> vec = {42};
    EXPECT_NO_THROW({
        bfprt(vec.begin(), vec.end(), 1);
    });
}

TEST(ExceptionTest, SingleElementInvalidK) {
    std::vector<int> vec = {42};
    EXPECT_THROW({
        bfprt(vec.begin(), vec.end(), 2);
    }, std::out_of_range);
}