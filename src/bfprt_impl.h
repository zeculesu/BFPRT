#ifndef BFPRT_IMPL_H
#define BFPRT_IMPL_H

#include <algorithm>
#include <iostream>


template <RandomAccessIterator It>
auto median_of_median(It left, It right) -> typename std::iterator_traits<It>::value_type {
    size_t size = std::distance(left, right);

    if (size % 2 == 1) {
        return nthSmallest(left, right, size / 2);
    } else {
        auto first = nthSmallest(left, right, size / 2 - 1);
        auto second = nthSmallest(left, right, size / 2);
        using ValueType = typename std::iterator_traits<It>::value_type;

        return (first + second) / static_cast<ValueType>(2);
    }
}


template <RandomAccessIterator It>
auto nthSmallest(It left, It right, std::size_t n) -> typename std::iterator_traits<It>::value_type {
    std::size_t size = std::distance(left, right);

    if (size == 0) {
        throw std::out_of_range("nthSmallest: empty range");
    }
    if (size == 1) {
        return *left;
    }
    if (n >= size) {
        throw std::out_of_range("nthSmallest: index out of range");
    }

    auto it = select(left, right, n);
    return *it;
}


template <RandomAccessIterator It>
It select(It left, It right, std::size_t n) {
    It pivotIndex;
    while (1) {
        if (left == right) return left;
        pivotIndex = pivot(left, right);
        pivotIndex = partition(left, right, pivotIndex, n);
        if (n == std::distance(left, pivotIndex)) return pivotIndex;
        else if (n < std::distance(left, pivotIndex)) right = pivotIndex;
        else left = pivotIndex + 1;
    }
}


template <RandomAccessIterator It>
It pivot(It left, It right) {
    if (std::distance(left, right) < 5) return partition5(left, right);

    It subRight, mediana5;

    for (auto i = left; i < right; i = i + 5) {
        subRight = i + 4;
        if (subRight >= right) { subRight = right - 1; }
        mediana5 = partition5(i, subRight);
        std::swap(*mediana5, *(left + std::distance(left, i) / 5));
    }

    auto mid = std::distance(left, right) / 10 + 1;
    return select(left, left + (right - left) / 5, mid);
}

template <RandomAccessIterator It>
It partition(It left, It right, It pivotIndex, std::size_t n) {
    if (std::distance(left, right) <= 0) return left;

    std::iter_swap(pivotIndex, right);
    auto pivotValue = *right;

    auto storeIndex = left;
    for (auto i = left; i != right; ++i) {
        if (*i < pivotValue) {
            std::swap(*i, *storeIndex);
            ++storeIndex;
        }
    }

    auto storeIndexEq = storeIndex;
    for (auto i = storeIndex; i != right; ++i) {
        if (*i == pivotValue) {
            std::swap(*i, *storeIndexEq);
            ++storeIndexEq;
        }
    }

    std::iter_swap(right, storeIndexEq);

    if (n < std::distance(left, storeIndex)) {
        return storeIndex;
    }
    if (n <= std::distance(left, storeIndexEq)) {
        return left + n;
    }
    return storeIndexEq;
}

template <RandomAccessIterator It>
It partition5(It left, It right) {
    std::sort(left, right);
    return left + (std::distance(left, right) / 2);
}

#endif