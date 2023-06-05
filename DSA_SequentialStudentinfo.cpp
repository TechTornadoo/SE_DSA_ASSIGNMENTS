//DSA_ASSIGNMENT11
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

void addStudent() {
    ofstream file("student.txt", ios::app);
    
    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);
    
    file << student.rollNo << " "
         << student.name << " "
         << student.division << " "
         << student.address << endl;
    
    file.close();
    
    cout << "Student information added successfully.\n";
}

void deleteStudent() {
    ifstream inFile("student.txt");
    ofstream outFile("temp.txt");
    
    int rollNo;
    cout << "Enter Roll No of the student to delete: ";
    cin >> rollNo;
    
    bool found = false;
    Student student;
    while (inFile >> student.rollNo >> student.name >> student.division >> student.address) {
        if (student.rollNo != rollNo) {
            outFile << student.rollNo << " "
                    << student.name << " "
                    << student.division << " "
                    << student.address << endl;
        } else {
            found = true;
        }
    }
    
    inFile.close();
    outFile.close();
    
    remove("student.txt");
    rename("temp.txt", "student.txt");
    
    if (found) {
        cout << "Student information deleted successfully.\n";
    } else {
        cout << "Student with Roll No " << rollNo << " not found.\n";
    }
}

void displayStudent() {
    ifstream file("student.txt");
    
    int rollNo;
    cout << "Enter Roll No of the student to display: ";
    cin >> rollNo;
    
    bool found = false;
    Student student;
    while (file >> student.rollNo >> student.name >> student.division >> student.address) {
        if (student.rollNo == rollNo) {
            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }
    
    file.close();
    
    if (!found) {
        cout << "Student with Roll No " << rollNo << " not found.\n";
    }
}

int main() {
    int choice;
    
    while (true) {
        cout << "--------------------------------------" << endl;
        cout << "Student Information Management System" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Thank you for using the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        cout << endl;
    }
}