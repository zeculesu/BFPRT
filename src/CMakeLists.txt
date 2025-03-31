add_library(BFPRTLib STATIC
    bfprt.cpp
)

target_compile_features(BFPRTLib PUBLIC cxx_std_20)
target_include_directories(BFPRTLib PUBLIC ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 20)
