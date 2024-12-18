// Develop an object oriented program in C++ to create a database of student information system containing the following information: 

// Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. etc 
// Construct the database with suitable member functions for initializing and destroying the data viz 
// constructor, default constructor, Copy constructor, destructor, static member functions, friend class, this pointer, inline 
// code and dynamic memory allocation operators-new and delete.

#include<iostream>
using namespace std;

class student;

class Display {

    public:
        void showDetails(student &s);

};

class student{

private:

    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string address;
    string telephone;
    string licenseNo;

public: 

    student(){
        name = "Unknown";
        rollNumber = 0;
        studentClass = "None";
        division = 'A';
        dob = "01-01-2000";
        bloodGroup = "N/A";
        address = "N/A";
        telephone = "0000000000";
        licenseNo = "N/A";
    }

    student(string n, int roll, string cls, char div, string birth, string blood, string addr, string phone, string license) {
        name = n;
        rollNumber = roll;
        studentClass = cls;
        division = div;
        dob = birth;
        bloodGroup = blood;
        address = addr;
        telephone = phone;
        licenseNo = license;
    }

    student(student &s){
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        telephone = s.telephone;
        licenseNo = s.licenseNo;
    }

    ~student(){
        cout << "Destructor called for: " << name << endl;
    }

    friend class Display;

    inline void showRollNumber(){
        cout << "Roll Number: " << rollNumber << endl;
    }

    static student* createStudent(){
        return new student();
    }

    static void deleteStudent(student *obj1){
        delete obj1;
    }

    void showInfo() {
        cout << "Student Info (" << this << ")" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Roll Number: " << this->rollNumber << endl;
    }

};

void Display :: showDetails(student &s){

    cout << "---- Student Details ----" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
    cout << "Class: " << s.studentClass << endl;
    cout << "Division: " << s.division << endl;
    cout << "Date of Birth: " << s.dob << endl;
    cout << "Blood Group: " << s.bloodGroup << endl;
    cout << "Address: " << s.address << endl;
    cout << "Telephone: " << s.telephone << endl;
    cout << "License No: " << s.licenseNo << endl;

};

int main(){

    student s1;  
    cout << "\nDefault Constructor:" << endl;
    s1.showInfo();

    student s2("Saish",101, "12th", 'B', "15-08-2003", "O+", "123 Street, City", "1234567890", "DL123456");
    s2.showInfo();

    student s3 = s2;
    cout << "\nCopy Constructor:" << endl;
    s3.showInfo();

    cout << "\nInline Function:" << endl;
    s3.showRollNumber();

    Display d;
    cout << "\nUsing Friend Class to Display Full Details of Student:" << endl;
    d.showDetails(s2);

    //Dynamic Memory Allocation
    student *s4 = student::createStudent();
    d.showDetails(*s4);
    student::deleteStudent(s4);

    return 0;
}