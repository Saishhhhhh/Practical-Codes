// Company maintains employee information as employee ID,name, designation and salary. 
// Allow user to add, delete information of employee. Display information of particular employee. 
// If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. 
// Use index sequential file to maintain the data.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;

    void writeToFile(ofstream& out) const {
        out.write(reinterpret_cast<const char*>(&employeeID), sizeof(employeeID));
        writeString(out, name);
        writeString(out, designation);
        out.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
    }

    void readFromFile(ifstream& in) {
        in.read(reinterpret_cast<char*>(&employeeID), sizeof(employeeID));
        name = readString(in);
        designation = readString(in);
        in.read(reinterpret_cast<char*>(&salary), sizeof(salary));
    }

    static void writeString(ofstream& out, const string& str) {
        size_t length = str.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(str.c_str(), length);
    }

    static string readString(ifstream& in) {
        size_t length;
        in.read(reinterpret_cast<char*>(&length), sizeof(length));
        string str(length, '\0');
        in.read(&str[0], length);
        return str;
    }
};

void addEmployee() {
    ofstream file("employee_data.dat", ios::binary | ios::app);
    Employee e;

    cout << "Enter employee ID: ";
    cin >> e.employeeID;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, e.name);

    cout << "Enter designation: ";
    getline(cin, e.designation);

    cout << "Enter salary: ";
    cin >> e.salary;

    e.writeToFile(file);
    file.close();
    cout << "Employee added successfully!\n";
}

void displayEmployee() {
    ifstream file("employee_data.dat", ios::binary);
    int searchID;
    bool found = false;

    cout << "Enter employee ID to search: ";
    cin >> searchID;

    while (file.peek() != EOF) {
        Employee e;
        e.readFromFile(file);
        if (e.employeeID == searchID) {
            found = true;
            cout << "\n--- Employee Details ---\n";
            cout << "ID         : " << e.employeeID << endl;
            cout << "Name       : " << e.name << endl;
            cout << "Designation: " << e.designation << endl;
            cout << "Salary     : " << e.salary << endl;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found!\n";
    }

    file.close();
}

void deleteEmployee() {
    int deleteID;
    bool found = false;
    cout << "Enter employee ID to delete: ";
    cin >> deleteID;

    ifstream file("employee_data.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.peek() != EOF) {
        Employee e;
        e.readFromFile(file);
        if (e.employeeID != deleteID) {
            e.writeToFile(temp);
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("employee_data.dat");
    rename("temp.dat", "employee_data.dat");

    if (found)
        cout << "Employee deleted successfully!\n";
    else
        cout << "Employee not found!\n";
}

int main() {
    int choice;

    cout << "Name: Anjali Shirke\tBatch: B1\tRoll No.: 23207\n";

    while (true) {
        cout << "\n--- Employee Information System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: displayEmployee(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
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