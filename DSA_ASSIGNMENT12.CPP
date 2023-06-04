#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    float salary;
};

class Company {
    vector<Employee> employees;

public:
    void addEmployee(int id, const string& name, const string& designation, float salary) {
        employees.push_back({ id, name, designation, salary });
        cout << "Employee added successfully!" << endl;
    }

    void deleteEmployee(int id) {
        auto it = find_if(employees.begin(), employees.end(), [&](const Employee& e) {
            return e.id == id;
        });

        if (it != employees.end()) {
            employees.erase(it);
            cout << "Employee deleted successfully!" << endl;
        } else {
            cout << "Employee does not exist!" << endl;
        }
    }

    void displayEmployee(int id) {
        auto it = find_if(employees.begin(), employees.end(), [&](const Employee& e) {
            return e.id == id;
        });

        if (it != employees.end()) {
            cout << "Employee ID: " << it->id << endl;
            cout << "Name: " << it->name << endl;
            cout << "Designation: " << it->designation << endl;
            cout << "Salary: " << it->salary << endl;
        } else {
            cout << "Employee does not exist!" << endl;
        }
    }
};

int main() {
    Company company;
    int choice, id;
    string name, designation;
    float salary;

    while (true) {
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter employee designation: ";
                cin >> designation;
                cout << "Enter employee salary: ";
                cin >> salary;
                company.addEmployee(id, name, designation, salary);
                break;
            case 2:
                cout << "Enter employee ID to delete: ";
                cin >> id;
                company.deleteEmployee(id);
                break;
            case 3:
                cout << "Enter employee ID to display: ";
                cin >> id;
                company.displayEmployee(id);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
