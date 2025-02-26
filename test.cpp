// test.cpp
#include <iostream>
#include <string>
#include <cassert>
#include "Student.h"
#include "Database.h"  // Replace with the actual header file

void testStudent() {
    Student student(1, "Test Student", 20, 3.5);

    assert(student.id == 1);
    assert(student.name == "Test Student");
    assert(student.age == 20);
    assert(student.gpa == 3.5);

    std::cout << "Student test passed!" << std::endl;
}

void testDatabase() {
    Database db;
    db.addStudent(1, "John Doe", 20, 3.5);
    db.addStudent(2, "Jane Smith", 22, 3.8);

    std::cout << "All students:" << std::endl;
    db.displayAll();

    // Check the find and remove functions
    std::cout << "Find student with ID 1:" << std::endl;
    db.findStudentById(1);
    db.removeStudentById(1);

    std::cout << "All students after removal:" << std::endl;
    db.displayAll();

    // Check that the student was removed
    assert(db.findStudentById(1) == -1);  // Assuming -1 indicates not found

    std::cout << "Database test passed!" << std::endl;
}

int main() {
    testStudent();
    testDatabase();
    return 0;
}
