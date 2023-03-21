#include <iostream>
#include "../Student.h"
#include <memory>

int main() {
    std::cout << "swap by value\n";
    
    // C++ 11: 列表初始化构造
    Student stu1 {"20170", "himu", 85.9}, stu2 {"20171", "mary", 98.9};
    std::cout << stu1 << " " << stu2 << std::endl;
    // swap 通过成员函数实现
    stu1.swap(stu2);
    std::cout << stu1 << " " << stu2 << std::endl;

    std::cout << "swap by pointer\n";
    // C++ 11: 智能指针避免内存泄漏
    std::shared_ptr<Student> ps1 = std::make_shared<Student>("20170", "himu", 85.9);
    std::shared_ptr<Student> ps2 = std::make_shared<Student>("20171", "mary", 98.9);
    std::cout << *ps1 << " " << *ps2 << std::endl;
    ps1->swap(ps2.get());
    std::cout << *ps1 << " " << *ps2 << std::endl;

    return 0;
}