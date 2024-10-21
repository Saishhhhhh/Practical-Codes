/*Aim: To understand and implement set operation using linked list.

Problem definition: Second year Computer Engineering class, set A of students like Vanilla Ice-cream and 
set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. 
compute and display 

i. Set of students who like either vanilla or butterscotch or both 
ii. Set of students who like both vanilla and butterscotch 
iii. Set of students who like only vanilla not butterscotch 
iv. Set of students who like only butterscotch not vanilla
v. Number of students who like neither vanilla nor butterscotch

*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

struct Node {
    string name;
    Node* next;

    Node(string name) : name(name), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addStudent(const string& name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    unordered_set<string> toSet() const {
        unordered_set<string> studentSet;
        Node* temp = head;
        while (temp) {
            studentSet.insert(temp->name);
            temp = temp->next;
        }
        return studentSet;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void displaySet(const unordered_set<string>& s) {
    if (s.empty()) {
        cout << "No students found.\n";
        return;
    }
    for (const auto& name : s) {
        cout << name << " ";
    }
    cout << endl;
}

int main() {
    LinkedList vanilla, butterscotch;

    int n, m;
    string name;

    cout << "Enter number of students who like Vanilla: ";
    cin >> n;
    cout << "Enter names of students who like Vanilla:\n";
    for (int i = 0; i < n; ++i) {
        cin >> name;
        vanilla.addStudent(name);
    }

    cout << "Enter number of students who like Butterscotch: ";
    cin >> m;
    cout << "Enter names of students who like Butterscotch:\n";
    for (int i = 0; i < m; ++i) {
        cin >> name;
        butterscotch.addStudent(name);
    }

    unordered_set<string> setVanilla = vanilla.toSet();
    unordered_set<string> setButterscotch = butterscotch.toSet();

    unordered_set<string> unionSet = setVanilla;
    unionSet.insert(setButterscotch.begin(), setButterscotch.end());

    unordered_set<string> intersectionSet;
    for (const auto& s : setVanilla) {
        if (setButterscotch.count(s)) {
            intersectionSet.insert(s);
        }
    }

    unordered_set<string> onlyVanilla;
    for (const auto& s : setVanilla) {
        if (!setButterscotch.count(s)) {
            onlyVanilla.insert(s);
        }
    }

    unordered_set<string> onlyButterscotch;
    for (const auto& s : setButterscotch) {
        if (!setVanilla.count(s)) {
            onlyButterscotch.insert(s);
        }
    }

    int totalStudents;
    cout << "Enter total number of students in class: ";
    cin >> totalStudents;
    int neitherCount = totalStudents - unionSet.size();

    cout << "\nStudents who like either Vanilla or Butterscotch or both:\n";
    displaySet(unionSet);

    cout << "\nStudents who like both Vanilla and Butterscotch:\n";
    displaySet(intersectionSet);

    cout << "\nStudents who like only Vanilla:\n";
    displaySet(onlyVanilla);

    cout << "\nStudents who like only Butterscotch:\n";
    displaySet(onlyButterscotch);

    cout << "\nNumber of students who like neither Vanilla nor Butterscotch: " << neitherCount << endl;

    return 0;
}

/*
    INPUT

Enter number of students who like Vanilla: 3
Enter names of students who like Vanilla:
Alice
Bob
Charlie
Enter number of students who like Butterscotch: 2
Enter names of students who like Butterscotch:
Bob
David
Enter total number of students in class: 5

*/
