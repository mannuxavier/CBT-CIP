#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    string personalInfo;
    string academicRecords;

    void input() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter personal information: ";
        getline(cin, personalInfo);
        cout << "Enter academic records: ";
        getline(cin, academicRecords);
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Personal Information: " << personalInfo << endl;
        cout << "Academic Records: " << academicRecords << endl;
    }
};

void addStudent() {
    Student student;
    student.input();

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << student.name << endl;
        file << student.rollNumber << endl;
        file << student.personalInfo << endl;
        file << student.academicRecords << endl;
        file.close();
        cout << "Student record added successfully!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void viewStudents() {
    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
