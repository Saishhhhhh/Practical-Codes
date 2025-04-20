// Company maintains employee information as employee ID,name, designation and salary. 
// Allow user to add, delete information of employee. Display information of particular employee. 
// If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. 
// Use index sequential file to maintain the data.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_NAME_LENGTH = 50;
const int MAX_DESIGNATION_LENGTH = 50;

struct Employee {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    char designation[MAX_DESIGNATION_LENGTH];
    double salary;
};

void addEmployee(fstream& file) {
    Employee employee;
    cout << "Enter employee ID: ";
    cin >> employee.employeeID;
    cin.ignore();

    cout << "Enter employee name: ";
    cin.getline(employee.name, MAX_NAME_LENGTH);

    cout << "Enter employee designation: ";
    cin.getline(employee.designation, MAX_DESIGNATION_LENGTH);

    cout << "Enter employee salary: ";
    cin >> employee.salary;

    file.clear(); // Clear flags
    file.seekp(0, ios::end); // Move to end for appending
    file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));

    cout << "Employee added successfully!" << endl;
}

void deleteEmployee(fstream& file) {
    int employeeID;
    bool found = false;
    Employee employee;

    cout << "Enter employee ID to delete: ";
    cin >> employeeID;

    fstream tempFile("temp.dat", ios::out | ios::binary);
    file.clear();
    file.seekg(0, ios::beg);

    while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        if (employee.employeeID != employeeID) {
            tempFile.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("employee_data.dat");
    rename("temp.dat", "employee_data.dat");

    if (found) {
        cout << "Employee deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }

    // Re-open file
    file.open("employee_data.dat", ios::in | ios::out | ios::binary);
}

void displayEmployee(fstream& file) {
    int employeeID;
    bool found = false;
    Employee employee;

    cout << "Enter employee ID to display: ";
    cin >> employeeID;

    file.clear();
    file.seekg(0, ios::beg);

    while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        if (employee.employeeID == employeeID) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID     : " << employee.employeeID << endl;
        cout << "Name            : " << employee.name << endl;
        cout << "Designation     : " << employee.designation << endl;
        cout << "Salary          : " << employee.salary << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    cout << "Name: Anjali Shirke\tBatch: B1\tRoll no. 23207" << endl;

    fstream file("employee_data.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        // If file doesn't exist, create it
        file.open("employee_data.dat", ios::out | ios::binary);
        file.close();
        file.open("employee_data.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    while (true) {
        cout << "\n--- Employee Information System ---" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                deleteEmployee(file);
                break;
            case 3:
                displayEmployee(file);
                break;
            case 4:
                file.close();
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

// 1
// Enter employee ID: 101
// Enter employee name: John Smith
// Enter employee designation: Software Engineer
// Enter employee salary: 75000
// Employee added successfully!

// 1
// Enter employee ID: 102
// Enter employee name: Alice Johnson
// Enter employee designation: Project Manager
// Enter employee salary: 95000
// Employee added successfully!

// 1
// Enter employee ID: 103
// Enter employee name: Robert Brown
// Enter employee designation: Data Analyst
// Enter employee salary: 65000
// Employee added successfully!

// 3
// Enter employee ID to display: 102
// --- Employee Details ---
// Employee ID     : 102
// Name            : Alice Johnson
// Designation     : Project Manager
// Salary          : 95000

// 2
// Enter employee ID to delete: 101
// Employee deleted successfully!

// 3
// Enter employee ID to display: 101
// Employee not found!

// 1
// Enter employee ID: 104
// Enter employee name: Sarah Wilson
// Enter employee designation: HR Manager
// Enter employee salary: 85000
// Employee added successfully!

// 3
// Enter employee ID to display: 103
// --- Employee Details ---
// Employee ID     : 103
// Name            : Robert Brown
// Designation     : Data Analyst
// Salary          : 65000

// 3
// Enter employee ID to display: 104
// --- Employee Details ---
// Employee ID     : 104
// Name            : Sarah Wilson
// Designation     : HR Manager
// Salary          : 85000

// 4
// Exiting program. Goodbye!