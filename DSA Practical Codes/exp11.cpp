// Department maintains a student information. The file contains roll number, name, division
// and address. Allow user to add, delete information of student. Display information of particular employee. 
// If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. 
// Use sequential file to main the data.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int rollNo;
    char name[20];
    char division;
    char address[50];

    void accept() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin >> address;
    }

    void editRoll() {
        cout << "Enter new Roll Number: ";
        cin >> rollNo;
    }

    void editName() {
        cout << "Enter new Name: ";
        cin >> name;
    }

    int getRollNo() {
        return rollNo;
    }

    void show() {
        cout << "\n" << rollNo << "\t" << name << "\t" << division << "\t" << address;
    }
};

int main() {
    cout << "Name: Anjali Shirke\tBatch: B1\tRoll no. 23207\n";

    fstream file, tempFile;
    Student s;
    int choice, roll, found = 0;
    char searchName[20];

    do {
        cout << "\n\n=========== MENU ===========";
        cout << "\n1. Insert & Overwrite";
        cout << "\n2. Show All Records";
        cout << "\n3. Search & Edit (by Roll Number)";
        cout << "\n4. Search & Edit (by Name)";
        cout << "\n5. Edit Only Roll Number";
        cout << "\n6. Edit Only Name";
        cout << "\n7. Delete a Student Record";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            file.open("StuRecord.txt", ios::out | ios::binary);
            char more;
            do {
                s.accept();
                file.write((char*)&s, sizeof(s));
                cout << "Add another record? (y/n): ";
                cin >> more;
            } while (more == 'y' || more == 'Y');
            file.close();
            break;
        }

        case 2: {
            file.open("StuRecord.txt", ios::in | ios::binary);
            cout << "\nRoll No\tName\tDivision\tAddress";
            while (file.read((char*)&s, sizeof(s))) {
                s.show();
            }
            file.close();
            break;
        }

        case 3: {
            cout << "Enter roll number to search and edit: ";
            cin >> roll;
            file.open("StuRecord.txt", ios::in | ios::out | ios::binary);
            found = 0;
            while (file.read((char*)&s, sizeof(s))) {
                if (s.getRollNo() == roll) {
                    cout << "\nRecord found. Enter new details:";
                    s.accept();
                    int pos = file.tellg();
                    file.seekp(pos - sizeof(s));
                    file.write((char*)&s, sizeof(s));
                    found = 1;
                    cout << "Record updated successfully.";
                    break;
                }
            }
            if (!found) cout << "Record not found.";
            file.close();
            break;
        }

        case 4: {
            cout << "Enter name to search and edit: ";
            cin >> searchName;
            file.open("StuRecord.txt", ios::in | ios::out | ios::binary);
            found = 0;
            while (file.read((char*)&s, sizeof(s))) {
                if (strcmp(s.name, searchName) == 0) {
                    cout << "\nRecord found. Enter new details:";
                    s.accept();
                    int pos = file.tellg();
                    file.seekp(pos - sizeof(s));
                    file.write((char*)&s, sizeof(s));
                    found = 1;
                    cout << "Record updated successfully.";
                    break;
                }
            }
            if (!found) cout << "Record not found.";
            file.close();
            break;
        }

        case 5: {
            cout << "Enter roll number to edit only the roll no: ";
            cin >> roll;
            file.open("StuRecord.txt", ios::in | ios::out | ios::binary);
            found = 0;
            while (file.read((char*)&s, sizeof(s))) {
                if (s.getRollNo() == roll) {
                    cout << "Record found.";
                    s.editRoll();
                    int pos = file.tellg();
                    file.seekp(pos - sizeof(s));
                    file.write((char*)&s, sizeof(s));
                    found = 1;
                    cout << "Roll number updated.";
                    break;
                }
            }
            if (!found) cout << "Record not found.";
            file.close();
            break;
        }

        case 6: {
            cout << "Enter name to edit only the name: ";
            cin >> searchName;
            file.open("StuRecord.txt", ios::in | ios::out | ios::binary);
            found = 0;
            while (file.read((char*)&s, sizeof(s))) {
                if (strcmp(s.name, searchName) == 0) {
                    cout << "Record found.";
                    s.editName();
                    int pos = file.tellg();
                    file.seekp(pos - sizeof(s));
                    file.write((char*)&s, sizeof(s));
                    found = 1;
                    cout << "Name updated.";
                    break;
                }
            }
            if (!found) cout << "Record not found.";
            file.close();
            break;
        }

        case 7: {
            cout << "Enter roll number to delete record: ";
            cin >> roll;
            file.open("StuRecord.txt", ios::in | ios::binary);
            tempFile.open("Temp.txt", ios::out | ios::binary);
            found = 0;
            while (file.read((char*)&s, sizeof(s))) {
                if (s.getRollNo() != roll) {
                    tempFile.write((char*)&s, sizeof(s));
                } else {
                    found = 1;
                }
            }
            file.close();
            tempFile.close();
            remove("StuRecord.txt");
            rename("Temp.txt", "StuRecord.txt");
            if (found)
                cout << "Record deleted successfully.";
            else
                cout << "Record not found.";
            break;
        }

        case 8:
            cout << "Thank you for using the system!";
            break;

        default:
            cout << "Invalid choice. Try again.";
        }

    } while (choice != 8);

    return 0;
}

// First, select option 1 to insert student records

// Enter Roll Number: 101
// Enter Name: John
// Enter Division: A
// Enter Address: Mumbai
// Add another record? (y/n): y

// Enter Roll Number: 102
// Enter Name: Alice
// Enter Division: B
// Enter Address: Delhi
// Add another record? (y/n): y

// Enter Roll Number: 103
// Enter Name: Bob
// Enter Division: A
// Enter Address: Pune
// Add another record? (y/n): n

// Select option 2 to view all records

// Select option 3 to search and edit by roll number:
// Enter roll number to search and edit: 102
// Record found. Enter new details:
// Enter Roll Number: 102
// Enter Name: Alice
// Enter Division: A
// Enter Address: Delhi
// Record updated successfully.

// Select option 4 to search and edit by name:
// Enter name to search and edit: Bob
// Record found. Enter new details:
// Enter Roll Number: 103
// Enter Name: Robert
// Enter Division: A
// Enter Address: Pune
// Record updated successful

// Select option 5 to edit only roll number:
// Enter roll number to edit only the roll no: 101
// Record found.
// Enter new Roll Number: 201
// Roll number updated.

// Select option 6 to edit only name:
// Enter name to edit only the name: Alice
// Record found.
// Enter new Name: Alicia
// Name updated.

// Select option 7 to delete a record:
// Enter roll number to delete record: 102
// Record deleted successfully.

// Select option 8 to exit the program.