#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>

#include "bfprt.h"

std::vector<int> generateRandomVector(size_t size, int minValue = -1000, int maxValue = 1000) {
    std::vector<int> vec(size);
    std::mt19937 rng(static_cast<unsigned int>(
        std::chrono::steady_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(minValue, maxValue);
    for (auto& val : vec) {
        val = dist(rng);
    }
    return vec;
}

TEST(BFPRTTest, VectorAndArray) {
    std::vector<std::vector<int>> testCases = {
        {3, 1, 2},
        {5, 2, 9, 1, 7},
        {10, 20, 30, 40, 50},
        {5, 5, 5, 5, 5},
        {1},
        {}
    };

    for (const auto& vec : testCases) {
        if (vec.empty()) continue;

        for (size_t k = 1; k <= vec.size(); ++k) {
            std::vector<int> arr = vec;
            std::vector<int> arrCopy = vec;

            int bfprtResult = bfprt(arr.begin(), arr.end(), static_cast<int>(k));
            std::nth_element(arrCopy.begin(), arrCopy.begin() + k - 1, arrCopy.end());
            int nthElementResult = arrCopy[k - 1];

            EXPECT_EQ(bfprtResult, nthElementResult)
                << "Failed on vector: " << ::testing::PrintToString(vec)
                << " with k = " << k;
        }

        std::array<int, 5> arrCopyArray;
        std::copy(vec.begin(), vec.begin() + std::min(vec.size(), size_t(5)), arrCopyArray.begin());
        for (size_t k = 1; k <= vec.size(); ++k) {
            std::array<int, 5> arr = arrCopyArray;

            int bfprtResult = bfprt(arr.begin(), arr.end(), static_cast<int>(k));
            std::nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
            int nthElementResult = arr[k - 1];

            EXPECT_EQ(bfprtResult, nthElementResult)
                << "Failed on array: " << ::testing::PrintToString(vec)
                << " with k = " << k;
        }
    }
}

TEST(BFPRTTest, LargeRandomVectors) {
    const size_t testSizes[] = {10, 100, 1000, 10000};
    for (size_t size : testSizes) {
        std::vector<int> vec = generateRandomVector(size);
        for (size_t k = 1; k <= 5; ++k) {
            size_t kth = k * size / 6;
            if (kth == 0) kth = 1;
            std::vector<int> arr = vec;
            std::vector<int> arrCopy = vec;

            int bfprtResult = bfprt(arr.begin(), arr.end(), static_cast<int>(kth));
            std::nth_element(arrCopy.begin(), arrCopy.begin() + kth - 1, arrCopy.end());
            int nthElementResult = arrCopy[kth - 1];

            EXPECT_EQ(bfprtResult, nthElementResult)
                << "Failed on vector of size: " << size << " with k = " << kth;
        }
    }
}

TEST(BFPRTTest, RepeatedElements) {
    std::vector<int> vec(1000, 42);
    std::array<int, 1000> arrCopyArray;
    std::copy(vec.begin(), vec.end(), arrCopyArray.begin());

    for (size_t k = 1; k <= vec.size(); k += 100) {
        std::vector<int> arr = vec;
        std::vector<int> arrCopy = vec;
        std::array<int, 1000> arrCopyArrayLocal = arrCopyArray;

        int bfprtResultVec = bfprt(arr.begin(), arr.end(), static_cast<int>(k));
        int bfprtResultArr = bfprt(arrCopyArrayLocal.begin(), arrCopyArrayLocal.end(), static_cast<int>(k));

        std::nth_element(arrCopy.begin(), arrCopy.begin() + k - 1, arrCopy.end());
        std::nth_element(arrCopyArrayLocal.begin(), arrCopyArrayLocal.begin() + k - 1, arrCopyArrayLocal.end());

        int nthElementResultVec = arrCopy[k - 1];
        int nthElementResultArr = arrCopyArrayLocal[k - 1];

        EXPECT_EQ(bfprtResultVec, nthElementResultVec);
        EXPECT_EQ(bfprtResultArr, nthElementResultArr);
    }
}

TEST(BFPRTTest, NegativeNumbers) {
    std::vector<int> vec = {-10, -50, -3, -4, -20, -1, -100};
    std::array<int, 7> arr = {-10, -50, -3, -4, -20, -1, -100};
    
    for (size_t k = 1; k <= vec.size(); ++k) {
        std::vector<int> arrVec = vec;
        std::array<int, 7> arrArray = arr;

        int bfprtResultVec = bfprt(arrVec.begin(), arrVec.end(), static_cast<int>(k));
        int bfprtResultArray = bfprt(arrArray.begin(), arrArray.end(), static_cast<int>(k));

        std::nth_element(arrVec.begin(), arrVec.begin() + k - 1, arrVec.end());
        std::nth_element(arrArray.begin(), arrArray.begin() + k - 1, arrArray.end());

        int nthElementResultVec = arrVec[k - 1];
        int nthElementResultArray = arrArray[k - 1];

        EXPECT_EQ(bfprtResultVec, nthElementResultVec);
        EXPECT_EQ(bfprtResultArray, nthElementResultArray);
    }
}
