// Aim: Write a C++ program that creates an output file, writes information to it, 
// closes the file and opens it again as an input file and reads the information from the file.

#include <iostream>
#include <fstream>
using namespace std;

class Employee {
    char name[20]; // Variable to store employee name
    int emp_id; // Variable to store employee ID
    float salary; // Variable to store employee salary
public:
    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> emp_id;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void display() const {
        cout << "\n" << name << "\t" << emp_id << "\t" << salary;
    }
};

int main() {
    Employee o[5]; // Array to store up to 5 employees
    fstream f;
    int n;

    // Open file for writing
    f.open("input.txt", ios::out | ios::binary);
    if (!f) {
        cout << "Error opening file for writing!" << endl;
        return 1; // Exit if the file cannot be opened
    }

    cout << "\nHow many employee information do you want to store (max 5): ";
    cin >> n;
    if (n > 5) {
        cout << "You can only store up to 5 employees." << endl;
        return 1;
    }

    cout << "\nEnter information of employees (name, emp_id, salary):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nEntering information for employee " << (i + 1) << ":";
        o[i].accept(); // Accept input from user
        f.write((char*)&o[i], sizeof(o[i])); // Write object to file
    }
    f.close(); // Close the file after writing

    // Open file for reading
    f.open("input.txt", ios::in | ios::binary);
    if (!f) {
        cout << "Error opening file for reading!" << endl;
        return 1; // Exit if the file cannot be opened
    }

    cout << "\nInformation of employees is as follows:";
    for (int i = 0; i < n; i++) {
        f.read((char*)&o[i], sizeof(o[i])); // Read data into object
        o[i].display(); // Display employee information
    }
    f.close(); // Close the file after reading

    return 0;
}


/* Example Input:
How many employee information do you want to store (max 5): 3
Entering information for employee 1:
Enter name: Alice
Enter employee ID: 101
Enter salary: 50000
Entering information for employee 2:
Enter name: Bob
Enter employee ID: 102
Enter salary: 55000
Entering information for employee 3:
Enter name: Charlie
Enter employee ID: 103
Enter salary: 60000
*/
