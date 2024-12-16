// Assignment no: 07
// Aim: To understand and implement singly linked list
// Problem definition: Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly, one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to
// a) Add and delete the members as well as president or even secretary.
// b) Compute total number of members of club
// c) Display members
// d) Display list in reverse order using recursion
// e) Two linked lists exist for two divisions. Concatenate two lists.

#include<iostream>
using namespace std;

struct Node{
    string name;
    int prn;
    Node *next;

    Node(string name1, int prn1, Node *next1){
        name = name1;
        prn = prn1;
        next = next1;
    }

    Node(string name1, int prn1){
        name = name1;
        prn = prn1;
        next = nullptr;
    }
};

Node *insertMember(Node *head, string name, int prn){

    Node *newNode = new Node(name,prn);

    if(head == nullptr){
        return newNode;
    }

    Node *temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
    
    return head;
}

Node *insertPresident(Node *head, string name, int prn){
    Node *newNode = new Node(name, prn);

    if(head == nullptr){
        return newNode;
    }

    //head = saish
    //temp = Saish
    Node *temp = head;
    
    //head = Anjali
    head = newNode;

    //Anjali->next = Saish
    newNode->next = temp;
    return head;
}

Node *insertSecretary(Node *head, string name, int prn){

    Node *newNode = new Node(name, prn);

    if(head == nullptr){
        return newNode;
    }

    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;

}

Node *deleteMember(Node *head, string name){

    if(head == nullptr){
        return head;
    }

    Node *temp = head;
    
    while(temp->next->name != name){
        temp = temp->next;
    }
    //Saish, Ayyub, Sayali, Sudhir, Anjali
    //temp = Ayyub
    Node *temp2 = temp->next;
    //temp2 = Sayali
    temp->next = temp2->next;
    //Ayyub->next = Sayali->Next(Sudhir)
    temp2->next = nullptr;
    //Sayali->next = nullptr
    delete temp2;
    //delete Sayali

    return head;
}

Node *deletePresident(Node *head){

    if(head == nullptr){
        return head;
    }

    Node *temp = head;

    head = temp->next;

    delete temp;

    return head;

}

Node *deleteSecretary(Node *head){

    if(head == nullptr){
        return head;
    }

    Node *temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;

}

int memberCount(Node *head){
    int count = 0;

    Node *temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }

    return count;
}

void display(Node *head){

    if (head == nullptr) {
    cout << "List is empty";
    return;
}

    Node *temp = head;
    while(temp != NULL){
        cout << temp->name << " " << temp->prn << endl;
        temp = temp->next;
    }
    cout << endl;
}

Node *concatenateLists(Node *head1, Node *head2){

    if(head1 == nullptr){
        return head2;
    }

    if(head2 == nullptr){
        return head1;
    }

    Node *temp = head1;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

void displayReverse(Node *head){

    if(head == nullptr){
        return;
    }

    displayReverse(head->next);
    cout << head->name << " " << head->prn << endl;
    
}

int main(){

    Node *president1 = nullptr;
    Node *president2 = nullptr;

    president1 = insertPresident(president1,"Saish",10);
    president1 = insertSecretary(president1,"Anjali",15);
    president1 = insertMember(president1, "Ayyub",11);
    president1 = insertMember(president1, "Himanshu",12);
    president1 = insertMember(president1, "Sayali",13);
    president1 = insertMember(president1, "Sudhir",14);
    
    president2 = insertPresident(president2,"A",20);
    president2 = insertSecretary(president2,"F",25);
    president2 = insertMember(president2, "B",21);
    president2 = insertMember(president2, "C",22);
    president2 = insertMember(president2, "D",23);
    president2 = insertMember(president2, "E",24);

    int count = memberCount(president1);
    cout << count;
    

    // president1 = concatenateLists(president1, president2);

    // president1 = deleteMember(president1, "Sayali");
    president1 = deletePresident(president1);
    // president1 = deleteSecretary(president1);

    display(president1);
    // cout << endl;
    // displayReverse(president2);

    return 0;
}