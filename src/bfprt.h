#ifndef BFPRT_H
#define BFPRT

#include <cstddef> 
#include <iterator>

#include <concepts>

template <typename It>
concept RandomAccessIterator = std::random_access_iterator<It>;

template <RandomAccessIterator It>
auto median_of_median(It left, It right) -> typename std::iterator_traits<It>::value_type;

template <RandomAccessIterator It>
auto nthSmallest(It left, It right, std::size_t n) -> typename std::iterator_traits<It>::value_type;

template <RandomAccessIterator It>
It select(It left, It right, std::size_t n);

template <RandomAccessIterator It>
It pivot(It left, It right);

template <RandomAccessIterator It>
It partition(It left, It right, It pivotIndex, std::size_t n);

template <RandomAccessIterator It>
It partition5(It left, It right);

#include "bfprt_impl.h"

#endif