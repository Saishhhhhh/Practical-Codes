// Company maintains employee information as employee ID,name, designation and salary. 
// Allow user to add, delete information of employee. Display information of particular employee. 
// If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. 
// Use index sequential file to maintain the data.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Simple employee structure
struct Employee {
    int id;
    string name;
    string designation;
    double salary;
};

// Function to add an employee
void addEmployee() {
    Employee emp;
    
    // Get employee details
    cout << "\nEnter Employee ID: ";
    cin >> emp.id;
    cin.ignore();
    
    cout << "Enter Name: ";
    getline(cin, emp.name);
    
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    
    cout << "Enter Salary: ";
    cin >> emp.salary;
    
    // Check if employee ID already exists
    bool idExists = false;
    ifstream checkIndex("employee_index.txt");
    if (checkIndex) {
        int id;
        long pos;
        while (checkIndex >> id >> pos) {
            if (id == emp.id) {
                idExists = true;
                break;
            }
        }
        checkIndex.close();
    }
    
    if (idExists) {
        cout << "\nError: Employee ID " << emp.id << " already exists!" << endl;
        return;
    }
    
    // Open data file to append the new employee
    ofstream dataFile("employee_data.txt", ios::app);
    if (!dataFile) {
        cout << "\nError: Cannot open data file for writing!" << endl;
        return;
    }
    
    // Remember position before writing
    long position = dataFile.tellp();
    
    // Write employee to data file
    dataFile << emp.id << "|" 
             << emp.name << "|" 
             << emp.designation << "|" 
             << emp.salary << endl;
    
    dataFile.close();
    
    // Add to index file - append only the ID and position
    ofstream indexFile("employee_index.txt", ios::app);
    if (!indexFile) {
        cout << "\nError: Cannot open index file for writing!" << endl;
        return;
    }
    
    indexFile << emp.id << " " << position << endl;
    indexFile.close();
    
    cout << "\nEmployee added successfully!" << endl;
}

// Function to search for an employee
void searchEmployee() {
    int searchId;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchId;
    
    // Look up the employee in the index
    ifstream indexFile("employee_index.txt");
    if (!indexFile) {
        cout << "\nNo employees found in database!" << endl;
        return;
    }
    
    bool found = false;
    long position = -1;
    int id;
    
    // Search for the ID in the index
    while (indexFile >> id >> position) {
        if (id == searchId) {
            found = true;
            break;
        }
    }
    
    indexFile.close();
    
    if (!found) {
        cout << "\nEmployee with ID " << searchId << " not found!" << endl;
        return;
    }
    
    // Open the data file and go to the position
    ifstream dataFile("employee_data.txt");
    if (!dataFile) {
        cout << "\nError: Cannot open data file for reading!" << endl;
        return;
    }
    
    dataFile.seekg(position);
    
    // Read the line with employee data
    string line;
    if (getline(dataFile, line)) {
        // Parse the line
        stringstream ss(line);
        string token;
        vector<string> tokens;
        
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 4) {
            int empId = stoi(tokens[0]);
            
            // Verify the ID matches
            if (empId == searchId) {
                cout << "\n--- Employee Details ---" << endl;
                cout << "ID: " << empId << endl;
                cout << "Name: " << tokens[1] << endl;
                cout << "Designation: " << tokens[2] << endl;
                cout << "Salary: " << tokens[3] << endl;
            } else {
                cout << "\nError: ID mismatch in data file. Database may be corrupted." << endl;
            }
        } else {
            cout << "\nError: Invalid data format in file." << endl;
        }
    } else {
        cout << "\nError: Could not read employee data from file." << endl;
    }
    
    dataFile.close();
}

// Function to delete an employee
void deleteEmployee() {
    int deleteId;
    cout << "\nEnter Employee ID to delete: ";
    cin >> deleteId;
    
    // Read the index file
    ifstream indexFile("employee_index.txt");
    if (!indexFile) {
        cout << "\nNo employees found in database!" << endl;
        return;
    }
    
    // Store all indices except the one to delete
    vector<pair<int, long>> indices;
    int id;
    long position;
    bool found = false;
    
    while (indexFile >> id >> position) {
        if (id == deleteId) {
            found = true;
        } else {
            indices.push_back(make_pair(id, position));
        }
    }
    
    indexFile.close();
    
    if (!found) {
        cout << "\nEmployee with ID " << deleteId << " not found!" << endl;
        return;
    }
    
    // Write the updated index back to file
    ofstream newIndexFile("employee_index.txt");
    if (!newIndexFile) {
        cout << "\nError: Cannot open index file for writing!" << endl;
        return;
    }
    
    for (const auto& entry : indices) {
        newIndexFile << entry.first << " " << entry.second << endl;
    }
    
    newIndexFile.close();
    
    cout << "\nEmployee deleted successfully!" << endl;
}

// Function to rebuild the index (for debugging)
void rebuildIndex() {
    // Open the data file
    ifstream dataFile("employee_data.txt");
    if (!dataFile) {
        cout << "\nNo employee data found to rebuild index!" << endl;
        return;
    }
    
    // Create a new index file
    ofstream indexFile("employee_index.txt");
    if (!indexFile) {
        cout << "\nError: Cannot create index file!" << endl;
        dataFile.close();
        return;
    }
    
    string line;
    long position = 0;
    
    while (getline(dataFile, line)) {
        stringstream ss(line);
        string token;
        
        if (getline(ss, token, '|')) {
            int id = stoi(token);
            indexFile << id << " " << position << endl;
        }
        
        position = dataFile.tellg();
    }
    
    dataFile.close();
    indexFile.close();
    
    cout << "\nIndex rebuilt successfully!" << endl;
}

// Function to reset the database (for debugging)
void resetDatabase() {
    // Remove existing files
    remove("employee_data.txt");
    remove("employee_index.txt");
    cout << "\nDatabase has been reset. All employee records deleted." << endl;
}

// Main function
int main() {
    int choice;
    
    do {
        cout << "\n===== EMPLOYEE MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Rebuild Index (Debug)" << endl;
        cout << "5. Reset Database (Debug)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: searchEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: rebuildIndex(); break;
            case 5: resetDatabase(); break;
            case 6: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}


