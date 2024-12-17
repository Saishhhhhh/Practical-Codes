// Aim: Write a C++ program using STL for sorting and searching user-defined 
// records such as Item records (Item code, name, cost, quantity, etc.) 
// using vector container.


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item {
public:
    char name[10];
    int quantity;
    int cost;
    int code;
    
    bool operator==(const Item& i1) const {
        return code == i1.code;
    }

    bool operator<(const Item& i1) const {
        return code < i1.code;
    }
};

vector<Item> o1;

void print(const Item &i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}

int main() {
    int ch;
    do {
        cout << "\n*** Menu ***";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: sort(o1.begin(), o1.end(), compare);
                    cout << "\n\nSorted on Cost";
                    display(); break;
            case 5: dlt(); break;
            case 6: exit(0);
        }
    } while(ch != 7);
    return 0;
}

void insert() {
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "\nEnter Item Quantity: ";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> i1.cost;
    cout << "\nEnter Item Code: ";
    cin >> i1.code;
    o1.push_back(i1);
}

void display() {
    for_each(o1.begin(), o1.end(), print);
}

void print(const Item &i1) {
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
}

void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if(p == o1.end()) {
        cout << "\nNot found.";
    } else {
        cout << "\nFound." << endl;
        cout << "Item Name: " << p->name << endl;
        cout << "Item Quantity: " << p->quantity << endl;
        cout << "Item Cost: " << p->cost << endl;
        cout << "Item Code: " << p->code << endl;
    }
}

void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if(p == o1.end()) {
        cout << "\nNot found.";
    } else {
        o1.erase(p);
        cout << "\nDeleted.";
    }
}

/* Required Input Format:

Input
Menu Options:

Insert
Display
Search
Sort
Delete
Exit
User Inputs:

Insert Item

Menu Selection: 1
Enter Item Name: Pen
Enter Item Quantity: 50
Enter Item Cost: 10
Enter Item Code: 101
Insert Another Item

Menu Selection: 1
Enter Item Name: Notebook
Enter Item Quantity: 30
Enter Item Cost: 25
Enter Item Code: 102
Insert Another Item

Menu Selection: 1
Enter Item Name: Eraser
Enter Item Quantity: 100
Enter Item Cost: 5
Enter Item Code: 103
Display All Items

Menu Selection: 2
Search for an Item

Menu Selection: 3
Enter Item Code to search: 102
Sort Items by Cost

Menu Selection: 4
Display All Items Again

Menu Selection: 2
Delete an Item

Menu Selection: 5
Enter Item Code to delete: 101
Display All Items Again

Menu Selection: 2
Exit the Program

Menu Selection: 6

*/
