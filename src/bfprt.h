#ifndef BFPRT_H
#define BFPRT_H

#include <algorithm>
#include <iterator>

template <typename It>
concept RandomAccessIterator = std::random_access_iterator<It>;

template <RandomAccessIterator It>
It partition(It first, It last, It pivotIt) {
    auto pivotValue = *pivotIt;
    std::swap(*(last - 1), *pivotIt);
    It store = first;
    for (It it = first; it < last - 1; ++it) {
        if (*it < pivotValue) {
            std::swap(*it, *store);
            ++store;
        }
    }
    std::swap(*(last - 1), *store); 
    return store;
}

template <RandomAccessIterator It>
It medianOfMedians(It first, It last) {
    auto size = std::distance(first, last);
    if (size <= 5) {
        std::sort(first, last);
        return first + size / 2;
    }

    It groupStart = first;
    It groupEnd;
    It medianIter;
    
    for (; groupStart < last; groupStart = groupEnd) {
        groupEnd = std::min(groupStart + 5, last);
        std::sort(groupStart, groupEnd);
        medianIter = groupStart + std::distance(groupStart, groupEnd) / 2;
        std::iter_swap(first + std::distance(first, groupStart) / 5, medianIter);
    }

    auto numMedians = (size + 4) / 5;
    return medianOfMedians(first, first + numMedians);
}

template <RandomAccessIterator It>
typename std::iterator_traits<It>::value_type
bfprt(It first, It last, int k) {
    int size = std::distance(first, last);

    if (size == 0) {
        throw std::invalid_argument("Empty range in bfprt()");
    }
    if (k <= 0 || k > size) {
        throw std::out_of_range("k is out of range in bfprt()");
    }

    if (size <= 5) {
        std::sort(first, last);
        std::advance(first, k - 1);
        return *first;
    }

    It pivotIt = medianOfMedians(first, last);
    It pivotFinal = partition(first, last, pivotIt);

    int rank = std::distance(first, pivotFinal) + 1;
    if (k == rank) {
        return *pivotFinal;
    } else if (k < rank) {
        return bfprt(first, pivotFinal, k);
    } else {
        return bfprt(pivotFinal + 1, last, k - rank);
    }
}

#endif
