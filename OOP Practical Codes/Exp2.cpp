#include <iostream>
#include <cstring>  // Use <cstring> instead of <string.h> in C++

using namespace std;

class person_additional_info {
    char address[20], license[20], insurance[20];
    long int contact;

public:
    // Default constructor
    person_additional_info() {
        strcpy(address, "XYZ");
        strcpy(license, "XY-0000000000");
        strcpy(insurance, "XY00000000X");
        contact = 0;
    }

    // Destructor
    ~person_additional_info() {
        cout << "I am in Destructor (person_additional_info)" << endl;
    }

    // Friend class declaration
    friend class person;
};

// Definition of the friend class
class person {
    char name[20], dob[10], blood[10];
    float ht, wt;
    static int count;  // Static variable to keep track of records
    person_additional_info *pai;

public:
    // Default constructor
    person() {
        strcpy(name, "XYZ");
        strcpy(dob, "dd/mm/yy");
        strcpy(blood, "A +");
        ht = 0;
        wt = 0;
        pai = new person_additional_info;
    }

    // Copy constructor
    person(const person &p1) {
        strcpy(name, p1.name);
        strcpy(dob, p1.dob);
        strcpy(blood, p1.blood);
        ht = p1.ht;
        wt = p1.wt;
        pai = new person_additional_info;
        strcpy(pai->address, p1.pai->address);
        strcpy(pai->license, p1.pai->license);
        strcpy(pai->insurance, p1.pai->insurance);
        pai->contact = p1.pai->contact;
    }

    // Destructor
    ~person() {
        cout << "\nI am in Destructor (person)" << endl;
        delete pai;  // Free dynamically allocated memory
    }

    // Static member function to display the count
    static void showcount() {
        cout << "\nNo of records count = " << count << "\n";
    }

    // Function to get data (using 'this' pointer)
    void getdata(char name[20]) {
        strcpy(this->name, name);
        cout << "\nEnter date of birth: ";
        cin >> dob;

        cout << "Enter blood group: ";
        cin >> blood;

        cout << "Enter height: ";
        cin >> ht;

        cout << "Enter weight: ";
        cin >> wt;

        cout << "Enter address: ";
        cin >> pai->address;

        cout << "Enter License number: ";
        cin >> pai->license;

        cout << "Enter Insurance policy number: ";
        cin >> pai->insurance;

        cout << "Enter Contact number: ";
        cin >> pai->contact;

        count++;
    }

    // Inline function to display data
    inline void display() const {
        cout << "\t" << name;
        cout << "\t" << dob;
        cout << "\t" << blood;
        cout << "\t" << ht;
        cout << "\t" << wt;
        cout << "\t" << pai->address;
        cout << "\t" << pai->license;
        cout << "\t" << pai->insurance;
        cout << "\t" << pai->contact;
    }
};

// Initialize static variable
int person::count = 0;

int main() {
    person *p1, *p2;
    int ch;

    // Dynamic memory allocation for person objects
    p1 = new person;  // Call default constructor
    p2 = new person(*p1);  // Call copy constructor

    cout << "\tName\tDob\tBlood\tHt\tWt\tAddress\tLicense\tInsurance\tContact\n";
    cout << "Default Constructor Value\n";
    p1->display();
    cout << "\nCopy Constructor Value\n";
    p2->display();
    
    int n;
    cout << "\nEnter how many records you want: ";
    cin >> n;

    person p3[n];  // Array of objects
    char name[20];
    int x = 0;

    do {
        cout << "\nWelcome to Personal Database System";
        cout << "\n1. Enter the record";
        cout << "\n2. Display the record";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "\nEnter the Name: ";
                cin >> name;
                p3[x].getdata(name);
                person::showcount();  // Call static function
                x++;
                break;
            }
            case 2: {
                cout << "\tName\tDob\tBlood\tHt\tWt\tAddress\tLicense\tInsurance\tContact\n";
                for (int i = 0; i < n; i++) {
                    cout << "\n";
                    p3[i].display();  // Call inline function
                }
                break;
            }
            case 3: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (ch != 3);

    // Free dynamically allocated memory
    delete p1;
    delete p2;

    return 0;
}

/* 
Sample Output:
Name    Dob    Blood   Ht   Wt   Address   License   Insurance   Contact
Default Constructor Value
XYZ     dd/mm/yy  A +  0    0    XYZ       XY-0000000000 XY00000000X 0
Copy Constructor Value
XYZ     dd/mm/yy  A +  0    0    XYZ       XY-0000000000 XY00000000X 0

Enter how many records you want: 2
Welcome to Personal Database System
1. Enter the record
2. Display the record
3. Exit
Enter your choice: 1

Enter the Name: abc
Enter date of birth: 15/5/2016
Enter blood group: o+
Enter height: 5
Enter weight: 50
Enter address: pune
Enter License number: jhdf87
Enter Insurance policy number: hdjsg7786
Enter Contact number: 989898989 (9 digits only)

No of records count = 1

Welcome to Personal Database System
1. Enter the record
2. Display the record
3. Exit
Enter your choice: 2

Name    Dob    Blood   Ht   Wt   Address   License   Insurance   Contact
abc     15/5/2016  o+  5    50   pune       jhdf87    hdjsg7786  989898989
XYZ     dd/mm/yy  A +  0    0    XYZ       XY-0000000000 XY00000000X 0
*/

