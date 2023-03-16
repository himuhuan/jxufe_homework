#include "Student.h"
#include <ostream>
#include <random>
#include <iomanip>

void Student::swap(Student *stu) {
    Student temp(*this);
    *this = *stu;
    *stu = temp;
}

void Student::swap(Student &stu) {
    std::swap(*this, stu);
}

std::ostream &operator<<(std::ostream &os, const Student &stu) {
    // std::quoted C++ 14 标准: 为字符串加上双引号
    os << "{" << std::quoted(stu.uid) << ", "
       << std::quoted(stu.name) << ", " << stu.admission_scores << "}";
    return os;
}

static const std::string student_names[] = {
    "Gabriel",
    "Healthy",
    "Miles",
    "Oswald",
    "Graham",
    "Derek",
    "Leonard",
    "Halden",
    "Keely",
    "Precious",
    "Deirdre",
    "Bound",
    "Zoe",
    "Kane",
    "Guide",
    "Peace",
    "Owner",
    "Doris",
    "Dixon",
    "Majestic",
};

std::vector<Student> generate_random_students(int n) {
    // C++ 11 标准: 生成真随机数
    // 参见: https://en.cppreference.com/w/cpp/header/random
    std::random_device seed;
    std::default_random_engine gen(seed());
    std::uniform_int_distribution<long> uid_distrib(10000000, 99999999);
    std::uniform_real_distribution<double> score_distrib(65.00, 100.0);
    std::uniform_int_distribution<int> name_distrib(0, 19);
    std::vector<Student> result;

    while (n-- > 0) {
        // C++ 11: 移动构造
        result.emplace_back(
            std::to_string(uid_distrib(gen)),
            student_names[name_distrib(gen)],
            score_distrib(gen)
        );
    }

    // RVO 优化
    return result;
}
