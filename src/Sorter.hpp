#pragma once

#ifndef SORTER_HPP_INC
#define SORTER_HPP_INC

#include <functional>

/**
 * @file Sorter.hpp
 * @brief Sorter describes all common sorting algorithms,
 * and to_sort describes a common interface to call Sorter.
 */
class Sorter {
public:
    // C++ STL: std::less<> 比较运算符 < 的模板实现
    // C++ 11: 默认模板
    template <typename Iter, typename cmp = std::less<>>
    void selectionSort(Iter start, Iter end, cmp compare = cmp()) {
        for (Iter p = start; p != end; std::advance(p, 1)) {
            // C++ STL: std::min_element 在一段范围内寻找最小量
            Iter min = std::min_element(p, end, compare);
            // C++ STL: 交换值
            std::swap(*min, *p);
        }
    }

    template <typename Iter, typename cmp = std::less<>>
    void insertionSort(Iter start, Iter end, cmp compare = cmp()) {
        for (auto p = start + 1; p != end; p++) {
            for (auto q = p; q != start && compare(*q, *(q-1)); q--)
                std::swap(*q, *(q-1));
        }
    } 
};

// C++ 11 类型别名
using DefaultCompare = std::less<>;

#endif