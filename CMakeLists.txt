cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
project(vector)

add_executable(vec src/main.cpp)

enable_testing()
add_executable(vector_tests tests.cpp)
target_include_directories(vector_tests PRIVATE src)
add_test(NAME vector_tests COMMAND vector_tests)
