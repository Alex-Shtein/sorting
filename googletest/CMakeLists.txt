cmake_minimum_required(VERSION 3.14)

project(mp_HW02)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_library(mp_HW02Lib SHARED ../Task2/src/main.cpp)

add_executable(mp_HW02Tests ../Task2.Tests/RadixSortTest.cpp ../Task2.Tests/SortParamTest.cpp)

target_link_libraries(mp_HW02Tests mp_HW02Lib gtest gtest_main pthread)