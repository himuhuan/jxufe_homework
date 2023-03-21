project(experiment_1)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(test_swap src/Student.h src/Student.cpp "src/Tests/TestSwap.cpp")
add_executable(test_sort src/Student.h src/Student.cpp src/Sorter.hpp "src/Tests/TestSort.cpp")
add_executable(test_seqlist "src/SeqList.hpp" "src/Tests/TestSeqList.cpp")
add_executable(test_linklist "src/LinkedList.hpp" "src/Tests/TestLinkedList.cpp")