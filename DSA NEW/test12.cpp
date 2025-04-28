// Company maintains employee information as employee ID,name, designation and salary. 
// Allow user to add, delete information of employee. Display information of particular employee. 
// If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. 
// Use index sequential file to maintain the data.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Employee structure to store employee information
 * Contains employee ID, name, designation, and salary
 * Also includes methods for file I/O operations
 */

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;

    /**
     * Writes employee data to binary file
     * @param out Output file stream to write to
     */
    
    void writeToFile(ofstream& out) const {
        out.write(reinterpret_cast<const char*>(&employeeID), sizeof(employeeID));
        writeString(out, name);
        writeString(out, designation);
        out.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
    }

    /**
     * Reads employee data from binary file
     * @param in Input file stream to read from
     */
    void readFromFile(ifstream& in) {
        in.read(reinterpret_cast<char*>(&employeeID), sizeof(employeeID));
        name = readString(in);
        designation = readString(in);
        in.read(reinterpret_cast<char*>(&salary), sizeof(salary));
    }

    /**
     * Helper method to write a string to binary file
     * @param out Output file stream
     * @param str String to write
     */
    static void writeString(ofstream& out, const string& str) {
        size_t length = str.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(str.c_str(), length);
    }

    /**
     * Helper method to read a string from binary file
     * @param in Input file stream
     * @return String read from file
     */
    static string readString(ifstream& in) {
        size_t length;
        in.read(reinterpret_cast<char*>(&length), sizeof(length));
        string str(length, '\0');
        in.read(&str[0], length);
        return str;
    }
};

/**
 * Function to add a new employee to the database
 * Gets employee details from user and writes to file
 */
void addEmployee() {
    // Open file in binary and append mode
    ofstream file("employee_data.dat", ios::binary | ios::app);
    Employee e;

    // Get employee details from user
    cout << "Enter employee ID: ";
    cin >> e.employeeID;
    cin.ignore();  // Clear input buffer after numeric input

    cout << "Enter name: ";
    getline(cin, e.name);

    cout << "Enter designation: ";
    getline(cin, e.designation);

    cout << "Enter salary: ";
    cin >> e.salary;

    // Write employee to file and close
    e.writeToFile(file);
    file.close();
    cout << "Employee added successfully!\n";
}

/**
 * Function to display information of a specific employee
 * Searches for employee by ID and displays details if found
 */
void displayEmployee() {
    // Open file in binary read mode
    ifstream file("employee_data.dat", ios::binary);
    int searchID;
    bool found = false;

    // Get employee ID to search
    cout << "Enter employee ID to search: ";
    cin >> searchID;

    // Read file until end or employee found
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
            break;  // Exit loop once employee is found
        }
    }

    // Display message if employee not found
    if (!found) {
        cout << "Employee not found!\n";
    }

    file.close();
}

/**
 * Function to delete an employee from the database
 * Creates a temporary file without the employee to delete
 */
void deleteEmployee() {
    int deleteID;
    bool found = false;
    
    // Get employee ID to delete
    cout << "Enter employee ID to delete: ";
    cin >> deleteID;

    // Open original file for reading and temp file for writing
    ifstream file("employee_data.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    // Copy all employees except the one to delete
    while (file.peek() != EOF) {
        Employee e;
        e.readFromFile(file);
        if (e.employeeID != deleteID) {
            e.writeToFile(temp);
        } else {
            found = true;  // Mark that employee was found
        }
    }

    // Close both files
    file.close();
    temp.close();

    // Replace original file with temp file
    remove("employee_data.dat");
    rename("temp.dat", "employee_data.dat");

    // Display appropriate message
    if (found)
        cout << "Employee deleted successfully!\n";
    else
        cout << "Employee not found!\n";
}

/**
 * Main function - Program entry point
 * Provides a menu-driven interface for employee management
 */
int main() {
    int choice;
    
    // Main program loop
    while (true) {
        // Display menu
        cout << "\n--- Employee Information System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Process user choice with if-else structure
        if (choice == 1) {
            addEmployee();
        }
        else if (choice == 2) {
            deleteEmployee();
        }
        else if (choice == 3) {
            displayEmployee();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            return 0;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}


// Test Case Examples:
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
