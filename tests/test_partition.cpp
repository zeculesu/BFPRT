#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <tuple>

#include "bfprt.h"

// Пользовательский тип для тестирования
struct Person {
    std::string name;
    int age;
    
    bool operator<(const Person& other) const { return age < other.age; }
    bool operator>=(const Person& other) const { return !(*this < other); }
    bool operator==(const Person& other) const { return age == other.age && name == other.name; }
};

TEST(PartitionTest, BasicPartitioningInt) {
    std::vector<int> vec = {3, 1, 4, 2, 5};
    auto pivotIt = vec.begin() + 2; // pivot = 4
    auto finalPos = partition(vec.begin(), vec.end(), pivotIt);

    for (auto it = vec.begin(); it != finalPos; ++it) {
        EXPECT_LT(*it, *finalPos);
    }
    for (auto it = finalPos + 1; it != vec.end(); ++it) {
        EXPECT_GE(*it, *finalPos);
    }
    EXPECT_EQ(*finalPos, 4);
}

TEST(PartitionTest, BasicPartitioningDouble) {
    std::vector<double> vec = {3.5, 1.1, 4.2, 2.7, 5.3};
    auto pivotIt = vec.begin() + 2; // pivot = 4.2
    auto finalPos = partition(vec.begin(), vec.end(), pivotIt);

    for (auto it = vec.begin(); it != finalPos; ++it) {
        EXPECT_LT(*it, *finalPos);
    }
    for (auto it = finalPos + 1; it != vec.end(); ++it) {
        EXPECT_GE(*it, *finalPos);
    }
    EXPECT_DOUBLE_EQ(*finalPos, 4.2);
}

TEST(PartitionTest, BasicPartitioningString) {
    std::vector<std::string> vec = {"banana", "apple", "orange", "grape", "cherry"};
    auto pivotIt = vec.begin() + 2; // pivot = "orange"
    auto finalPos = partition(vec.begin(), vec.end(), pivotIt);

    for (auto it = vec.begin(); it != finalPos; ++it) {
        EXPECT_LT(*it, *finalPos);
    }
    for (auto it = finalPos + 1; it != vec.end(); ++it) {
        EXPECT_GE(*it, *finalPos);
    }
    EXPECT_EQ(*finalPos, "orange");
}

TEST(PartitionTest, CustomTypePartitioning) {
    std::vector<Person> vec = {
        {"Alice", 30},
        {"Bob", 20},
        {"Charlie", 25},
        {"Dave", 35},
        {"Eve", 22}
    };
    auto pivotIt = vec.begin() + 2; // pivot = Charlie, 25
    auto finalPos = partition(vec.begin(), vec.end(), pivotIt);

    for (auto it = vec.begin(); it != finalPos; ++it) {
        EXPECT_LT(it->age, finalPos->age);
    }
    for (auto it = finalPos + 1; it != vec.end(); ++it) {
        EXPECT_GE(it->age, finalPos->age);
    }
    EXPECT_EQ(finalPos->name, "Charlie");
    EXPECT_EQ(finalPos->age, 25);
}

TEST(PartitionTest, AlreadyPartitionedString) {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "grape", "orange"};
    auto pivotIt = vec.begin() + 2; // pivot = "cherry"
    auto finalPos = partition(vec.begin(), vec.end(), pivotIt);

    EXPECT_EQ(finalPos, vec.begin() + 2);
    EXPECT_EQ(vec, (std::vector<std::string>{"apple", "banana", "cherry", "grape", "orange"}));
}