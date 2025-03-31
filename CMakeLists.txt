cmake_minimum_required(VERSION 3.21)
project(BFPRT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)