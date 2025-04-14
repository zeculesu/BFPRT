#ifndef BFPRT_H
#define BFPRT_H

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <sstream>

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
        std::ostringstream oss;
        oss << "Error: Empty range in bfprt()\n"
            << "Function parameters:\n"
            << "  First iterator value: " << (first != last ? *first : -1) << "\n"
            << "  Size of range: " << size << "\n"
            << "  Requested k: " << k;
        throw std::invalid_argument(oss.str());
    }

    if (k <= 0 || k > size) {
        std::ostringstream oss;
        oss << "Error: k is out of range in bfprt()\n"
            << "Function parameters:\n"
            << "  First iterator value: " << *first << "\n"
            << "  Last iterator value: " << *std::prev(last) << "\n"
            << "  Size of range: " << size << "\n"
            << "  Requested k: " << k;
        throw std::out_of_range(oss.str());
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
