#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student {
    public: 
    int rollNo;
    char name[50];
    char division;
    char address[100];

    Student(){
        rollNo = 0;
        strcpy(name, "");
        division = ' ';
        strcpy(address, "");
    }

    void getStudentData() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // Clear buffer

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Division: ";
        cin >> division;
        cin.ignore(); // Clear buffer

        cout << "Enter Address: ";
        cin.getline(address, 100);
    }

    // Getter for roll number
    int getRollNo() {
        return rollNo;
    }

    void displayStudentData() {
        cout << "\n------------------------------------";
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nDivision: " << division;
        cout << "\nAddress: " << address;
        cout << "\n------------------------------------";
    }
};

void addStudent(){
    Student student;
    ofstream outFile;

    outFile.open("students.dat", ios :: out | ios :: app | ios :: binary);

    if(!outFile){
        cout << "\nError: Cannot open file!";
        return;
    }

    student.getStudentData();

    outFile.write((char *)&student, sizeof(Student));

    outFile.close();

    cout << "Student record added successfully!";
}

void displayStudent(){
    int rollNo;
    bool found = false;
    Student student;
    ifstream inFile;

    inFile.open("students.dat", ios::in | ios::binary);

    if(!inFile){
        cout << "\nError: File could not be opened or does not exist!";
        return;
    }

    cout << "Enter Roll number to search: ";
    cin >> rollNo;

    while(inFile.read((char *)&student, sizeof(Student))){
        if(student.getRollNo() == rollNo){
            student.displayStudentData();
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "\nError: Student with Roll Number " << rollNo << " not found!";
    }
}

void deleteStudent(){
    int rollNo;
    bool found = false;
    Student student;

    // Open input file
    ifstream inFile;
    inFile.open("students.dat", ios::in | ios::binary);
    
    if (!inFile) {
        cout << "\nError: File could not be opened or does not exist!";
        return;
    }

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    
    // Get roll number to delete
    cout << "\nEnter Roll Number to delete: ";
    cin >> rollNo;

    while (inFile.read((char *)&student, sizeof(Student))){
        if(student.getRollNo() != rollNo){
            outFile.write((char *)&student, sizeof(Student));
        }else{
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("students.dat");

    rename("temp.dat", "students.dat");

    if (found) {
        cout << "\nStudent record deleted successfully!";
    } else {
        cout << "\nError: Student with Roll Number " << rollNo << " not found!";
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n\n==== STUDENT INFORMATION SYSTEM ====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Student";
        cout << "\n3. Delete Student";
        cout << "\n4. Exit";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
                
            case 2:
                displayStudent();
                break;
                
            case 3:
                deleteStudent();
                break;
                
            case 4:
                cout << "\nExiting program... Thank you!";
                break;
                
            default:
                cout << "\nInvalid Choice! Please try again.";
        }
    } while (choice != 4);
    
    return 0;
}