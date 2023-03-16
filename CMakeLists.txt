project(experiment_1)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_CXX_STANDARD 17)

add_executable(test_swap src/Student.h src/Student.cpp src/swap_test.cpp)
add_executable(exec src/Student.h src/Student.cpp src/Sorter.hpp src/test_sort.cpp)
