/*Aim: To understand and implement singly linked list
Problem definition: Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly, one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exist for two divisions. Concatenate two lists.
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string prn;
    Node* next;

    Node(string prn, string name) : prn(prn), name(name), next(nullptr) {}
};

class PinnacleClub {
private:
    Node* head;
    Node* tail;

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    void addMember(string prn, string name, bool isPresident = false, bool isSecretary = false) {
        Node* newNode = new Node(prn, name);
        
        if (isPresident) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = newNode;
        } else if (isSecretary) {
            if (tail != nullptr) tail->next = newNode;
            tail = newNode;
            if (head == nullptr) head = newNode;
        } else {
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void deleteMember(string prn) {
        if (!head) {
            cout << "No members to delete.\n";
            return;
        }

        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next && current->next->prn != prn) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) tail = current;
            delete temp;
        } else {
            cout << "Member with PRN " << prn << " not found.\n";
        }
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void displayMembers() {
        if (!head) {
            cout << "No members in the club.\n";
            return;
        }
        Node* temp = head;
        cout << "Club Members:\n";
        while (temp) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void displayReverse(Node* node) {
        if (!node) return;
        displayReverse(node->next);
        cout << "PRN: " << node->prn << ", Name: " << node->name << endl;
    }

    void displayReverse() {
        cout << "Members in Reverse Order:\n";
        displayReverse(head);
    }

    void concatenate(PinnacleClub& other) {
        if (!head) {
            head = other.head;
            tail = other.tail;
        } else if (other.head) {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = other.tail = nullptr;
    }

    ~PinnacleClub() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PinnacleClub divA, divB;

    divA.addMember("101", "Alice", true);
    divA.addMember("102", "Bob");
    divA.addMember("103", "Charlie", false, true);

    divB.addMember("201", "David", true);
    divB.addMember("202", "Eve");
    divB.addMember("203", "Frank", false, true);

    cout << "Division A:\n";
    divA.displayMembers();

    cout << "\nDivision B:\n";
    divB.displayMembers();

    divA.concatenate(divB);

    cout << "\nAfter Concatenation (Division A + Division B):\n";
    divA.displayMembers();

    cout << "\nDisplaying in Reverse Order:\n";
    divA.displayReverse();

    cout << "\nTotal Members: " << divA.countMembers() << endl;

    divA.deleteMember("102");
    cout << "\nAfter Deleting Bob:\n";
    divA.displayMembers();

    return 0;
}
