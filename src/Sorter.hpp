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
    // C++ STL: std::less<> �Ƚ������ < ��ģ��ʵ��
    // C++ 11: Ĭ��ģ��
    template <typename Iter, typename cmp = std::less<>>
    void selectionSort(Iter start, Iter end, cmp compare = cmp()) {
        for (Iter p = start; p != end; std::advance(p, 1)) {
            // C++ STL: std::min_element ��һ�η�Χ��Ѱ����С��
            Iter min = std::min_element(p, end, compare);
            // C++ STL: ����ֵ
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

// C++ 11 ���ͱ���
using DefaultCompare = std::less<>;

#endif