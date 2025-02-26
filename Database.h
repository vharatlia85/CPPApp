#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>

class Database {
private:
    std::vector<Student> students;

public:
    void addStudent(int id, std::string name, int age, float gpa) {
        students.push_back(Student(id, name, age, gpa));
    }

    void displayAll() {
        for (Student& s : students) {
            s.display();
        }
    }

    int findStudentById(int id) {
        for (Student& s : students) {
            if (s.id == id) {
                s.display();
                return id;
            }
        }
        std::cout << "Student not found!" << std::endl;
        return -1;  // Indicate student not found
    }

    void removeStudentById(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                std::cout << "Student removed!" << std::endl;
                return;
            }
        }
        std::cout << "Student not found!" << std::endl;
    }
};

#endif
