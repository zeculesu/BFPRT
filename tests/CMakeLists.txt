find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBRARY_DIRS})

set(TEST_SOURCES)
file(GLOB TEST_SOURCES ${CMAKE_SOURCE_DIR}/tests/test_*.cpp)


foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_FILE})

    target_link_libraries(${TEST_NAME} GTest::GTest GTest::Main BFPRTLib)
    target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
