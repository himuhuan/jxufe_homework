#pragma once
#ifndef STUDENT_H_INC
#define STUDENT_H_INC

#include <string>
#include <utility>
#include <vector>
#include <iosfwd>

/**
 * @brief the Record of a Student
 */
struct Student {
    std::string uid;
    std::string name;
    double admission_scores;

    Student(std::string u, std::string n, double score)
        : uid(std::move(u)), name(std::move(n)), admission_scores(score)
    {  }
    Student(const Student & stu) = default;
    Student & operator=(const Student & s) = default;
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);

    void swap(Student *stu);
    void swap(Student & stu);
};

std::vector<Student> generate_random_students(int n);

#endif //! STUDENT_H_INC