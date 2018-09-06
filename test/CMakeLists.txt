cmake_minimum_required(VERSION 3.9)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp ElementTest.cpp ListElementFixture.cpp)
add_executable(unitTesting ${SOURCE_TEST_FILES})

target_link_libraries(unitTesting gtest gtest_main core)