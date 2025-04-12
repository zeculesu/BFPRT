find_package(benchmark REQUIRED)

add_executable(bfprt_benchmarks test_performance.cpp)

target_include_directories(bfprt_benchmarks PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(bfprt_benchmarks PRIVATE BFPRTLib benchmark::benchmark)
