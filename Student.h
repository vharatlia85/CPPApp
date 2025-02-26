#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    int id;
    std::string name;
    int age;
    float gpa;

    Student(int id, std::string name, int age, float gpa) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void display() {
        std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;
    }
};

#endif
