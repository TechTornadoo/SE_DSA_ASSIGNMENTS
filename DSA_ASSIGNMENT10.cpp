#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Patient {
public:
    string name;
    string condition;
    
    Patient(const string& name, const string& condition) : name(name), condition(condition) {}
    
    // Overloading the less than operator to define the priority order
    bool operator<(const Patient& other) const {
        // Lower number indicates higher priority
        if (condition == "serious") {
            return true; // Patients with serious condition have the highest priority
        } else if (condition == "non-serious" && other.condition != "serious") {
            return true; // Non-serious patients have priority over general check-up patients
        }
        return false;
    }
};

int main() {
    priority_queue<Patient> patientQueue;

    // Adding patients to the priority queue
    patientQueue.push(Patient("John", "non-serious"));
    patientQueue.push(Patient("Sarah", "serious"));
    patientQueue.push(Patient("Mike", "general check-up"));
    patientQueue.push(Patient("Emily", "non-serious"));
    patientQueue.push(Patient("David", "serious"));
    patientQueue.push(Patient("Amy", "non-serious"));
    patientQueue.push(Patient("Daniel", "general check-up"));

    // Serving patients in the order of their priority
    while (!patientQueue.empty()) {
        Patient currentPatient = patientQueue.top();
        patientQueue.pop();

        cout << "Serving patient: " << currentPatient.name << " (Condition: " << currentPatient.condition << ")" << endl;
    }

    return 0;
}
