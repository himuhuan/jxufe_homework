#include "SeqList.hpp"
#include <iostream>
#include <algorithm>

int main() {
    SeqList<int> l1;
    for (int i = 0; i < 10; i++) {
        l1.push_back(i);
    }
    l1.display();
    std::clog << "the size of l1: " << l1.size()
              << ", " << "capacity: " << l1.capacity() << std::endl;
    l1.insert(5, -1);
    l1.display();
    std::clog << "the size of l1: " << l1.size()
              << ", " << "capacity: " << l1.capacity() << std::endl;
    l1.remove(0);
    l1.display();
    l1.remove(l1.find(6));
    l1.display();
    l1.clear();
    l1.display();
    std::clog << "the size of l1: " << l1.size()
              << ", " << "capacity: " << l1.capacity() << std::endl;
    for (int i = 20; i > 0; i--) {
        l1.push_back(i);
    }
    l1.display();
    std::sort(l1.begin(), l1.end());
    l1.display();
    std::clog << "min of l1: " << l1[0] << std::endl;
    std::clog << "the size of l1: " << l1.size()
              << ", " << "capacity: " << l1.capacity() << std::endl;
    l1.resize(10);
    l1.display();
    std::clog << "the size of l1: " << l1.size()
              << ", " << "capacity: " << l1.capacity() << std::endl;
    return 0;
}