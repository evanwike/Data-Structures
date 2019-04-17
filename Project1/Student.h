#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <iostream>
#include <string>
using std::string;

class Student {
public:
    string name;
    Student *next;
    explicit Student(const string &name) {
        this->name = name;
        next = nullptr;
    }
};

#endif //PROJECT1_STUDENT_H
