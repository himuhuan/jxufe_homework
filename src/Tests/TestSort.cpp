//
// Created by himu on 23-3-16.
//

#include "../Student.h"
#include "../Sorter.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    // C++ 11 列表构造
    auto v1 {generate_random_students(20)};
    std::vector<Student> v2 = v1, v3 = v1;
    // C++ 11 基于迭代器的for-each
    for (auto & stu : v1)
        std::cout << stu << std::endl;

    Sorter s;
    std::cout << "---------- Insert Sort(by score) ----------\n";
    // C++ 11: 匿名函数 lambda 表达式, 生成一个可供模板使用的函数对象
    s.insertionSort(v1.begin(), v1.end(), [](const Student & s1, const Student & s2) {
        return s1.admission_scores < s2.admission_scores;
    });
    for (auto & stu : v1)
        std::cout << stu << std::endl;
     
    std::cout << "---------- Selection Sort(by name) ----------\n";
    s.selectionSort(v2.begin(), v2.end(), [](const Student & s1, const Student & s2) {
        return s1.name < s2.name;
    });
    for (auto & stu : v2)
        std::cout << stu << std::endl;

    std::cout << "---------- Quick Sort(std::sort, by uid) ----------\n";
    std::sort(v3.begin(), v3.end(), [](const Student & s1, const Student & s2) {
        return s1.uid < s2.uid;
    });
    for (auto & stu : v3)
        std::cout << stu << std::endl;
    return 0;
}