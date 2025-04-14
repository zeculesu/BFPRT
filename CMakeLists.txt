cmake_minimum_required(VERSION 3.21)
project(BFPRT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
add_subdirectory(benchmarks)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE BFPRTLib)
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/src)
