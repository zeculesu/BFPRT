#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <random>
#include "bfprt.h"

std::mt19937 rng(42);

std::vector<int> generateRandomVector(size_t size, std::mt19937& rng) {
    std::vector<int> vec(size);
    std::uniform_int_distribution<int> dist(1, 10000);
    
    for (auto& v : vec) {
        v = dist(rng);
    }
    return vec;
}

static void BM_StdNthElement(benchmark::State& state) {
    auto size = state.range(0);
    auto k = state.range(1);
    auto data = generateRandomVector(size, rng);
    
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> vec = data;
        state.ResumeTiming();
        std::nth_element(vec.begin(), vec.begin() + k - 1, vec.end());
        benchmark::DoNotOptimize(vec[k-1]);
    }
    state.SetComplexityN(size);
}

static void BM_BFPRT(benchmark::State& state) {
    auto size = state.range(0);
    auto k = state.range(1);
    auto data = generateRandomVector(size, rng);
    
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> vec = data;
        state.ResumeTiming();
        int result = bfprt(vec.begin(), vec.end(), k);
        benchmark::DoNotOptimize(result);
    }
    state.SetComplexityN(size);
}

BENCHMARK(BM_StdNthElement)
    ->Args({100, 50})       // Маленький массив (100 элементов), медиана
    ->Args({1000, 500})     // Средний массив
    ->Args({10000, 5000})   // Большой массив
    ->Args({100000, 50000}) // Очень большой массив
    ->Complexity();

BENCHMARK(BM_BFPRT)
    ->Args({100, 50})
    ->Args({1000, 500})
    ->Args({10000, 5000})
    ->Args({100000, 50000})
    ->Complexity();

BENCHMARK_MAIN();