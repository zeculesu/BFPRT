#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <list>
#include <string>
#include "bfprt.h"


TEST(Partition5Test, BasicTest) {
    std::vector<int> data = {5, 3, 1, 4, 2};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, 3);
}

TEST(Partition5Test, CharTest) {
    std::vector<char> data = {'e', 'c', 'a', 'd', 'b'};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, 'c');
}

TEST(Partition5Test, EdgeCase) {
    std::vector<int> data = {1, 2, 3};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, 2);
}

TEST(Partition5Test, SingleElement) {
    std::vector<int> data = {5};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, 5);
}

TEST(Partition5Test, ArrayTest) {
    std::array<int, 5> data = {10, 20, 30, 40, 50};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, 30);
}

TEST(Partition5Test, RawPointerTest) {
    int data[] = {9, 7, 5, 3, 1};
    auto left = data;
    auto right = data + 5;

    auto median = partition5(left, right);

    EXPECT_EQ(*median, 5);
}

TEST(Partition5Test, StringTest) {
    std::vector<std::string> data = {"apple", "orange", "banana", "grape", "pear"};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, "grape");
}

TEST(Partition5Test, ArrayStringTest) {
    std::array<std::string, 5> data = {"apple", "orange", "banana", "grape", "pear"};
    auto left = data.begin();
    auto right = data.end();

    auto median = partition5(left, right);

    EXPECT_EQ(*median, "grape");
}
