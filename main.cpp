#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    float gpa;

    Student(int id, string name, int age, float gpa) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

class Database {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, int age, float gpa) {
        students.push_back(Student(id, name, age, gpa));
    }

    void displayAll() {
        for (Student& s : students) {
            s.display();
        }
    }

    void findStudentById(int id) {
        for (Student& s : students) {
            if (s.id == id) {
                s.display();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void removeStudentById(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student removed!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

int main() {
    Database db;
    db.addStudent(1, "John Doe", 20, 3.5);
    db.addStudent(2, "Jane Smith", 22, 3.8);

    cout << "All students:" << endl;
    db.displayAll();

    cout << "Find student with ID 1:" << endl;
    db.findStudentById(1);

    cout << "Removing student with ID 1:" << endl;
    db.removeStudentById(1);

    cout << "All students after removal:" << endl;
    db.displayAll();

    return 0;
}
