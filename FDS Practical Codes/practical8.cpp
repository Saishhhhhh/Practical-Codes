// Assignment no: 08

// Aim: To understand and implement set operation using linked list.

// Problem definition: Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. compute and display i. Set of students who like either vanilla or butterscotch or both ii. Set of students who like both vanilla and butterscotch iii. Set of students who like only vanilla not butterscotch iv. Set of students who like only butterscotch not vanilla
// v. Number of students who like neither vanilla nor butterscotch

#include<iostream>
using namespace std;

struct Node{
    string name;
    Node *next;

    Node(string name1, Node *next1){
        name = name1;
        next = next1;
    }

    Node(string name1){
        name = name1;
        next = nullptr;
    }
};

Node *arraytoLL(string arr[], int size){

    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i < size; i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
};

void intersection(Node* head1,Node *head2){

    Node *temp1 = head1;
    
    while(temp1!=NULL){
        Node *temp2 = head2;
        while(temp2!=NULL){
            if(temp1->name == temp2->name){
                cout << temp1->name << " ";
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void onlyVanilla(Node* head1,Node *head2){

    Node *temp1 = head1;
    
    while(temp1!=NULL){
        Node *temp2 = head2;
        
        while(temp2!=NULL){
            if(temp1->name == temp2->name){
                break;
            }
            temp2 = temp2->next;
        }

        if(temp2 == NULL){
            cout << temp1->name << " ";
        }
        temp1 = temp1->next;
    }
}

void onlyButterScotch(Node* head1,Node *head2){

    Node *temp2 = head2;
    
    while(temp2!=NULL){
        Node *temp1 = head1;
        
        while(temp1!=NULL){
            if(temp2->name == temp1->name){
                break;
            }
        
            temp1 = temp1->next;
        }

        if(temp1 == NULL){
            cout << temp2->name << " ";
        }
        temp2 = temp2->next;
    }
};

void BothFlavours(Node* head1,Node *head2){

    onlyVanilla(head1,head2);
    intersection(head1,head2);
    onlyButterScotch(head1,head2);

};

void Neither(Node* head1, Node* head2, Node*head3){
    
    Node *temp1 = head1;

    while(temp1!=NULL){

        Node *temp2 = head2;
        Node *temp3 = head3;

        while(temp2!=NULL){

            if(temp1->name == temp2->name){
                break;
            }
            temp2 = temp2->next;
        }
        while(temp3!=NULL){
            if(temp1->name == temp3->name){
                break;
            }
            temp3=temp3->next;  
        }

        if(temp2 == NULL && temp3 == NULL){
            cout << temp1->name << " ";
        }

        temp1 = temp1->next;
    }
}

void display(Node *head){

    if(head == nullptr){
        cout << "List is empty";
    }

    Node *temp = head;

    while(temp!=NULL){
        cout << temp->name << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){

    Node *students = nullptr;
    Node *vanilla = nullptr;
    Node *butterscotch = nullptr;
    Node *NoFlavour = nullptr;

    string studentsArr[12] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};

    string vanillaArr[5] = {"A", "B", "C", "D", "E"};
    string butterscotchArr[7] = {"D","E", "F", "G", "H", "I", "J"};
    // string NoFlavourArr[2] = {"K", "L"};

    students = arraytoLL(studentsArr, 12);
    vanilla = arraytoLL(vanillaArr, 5);
    butterscotch = arraytoLL(butterscotchArr, 7);
    // NoFlavour = arraytoLL(NoFlavourArr, 2);
    // display(vanilla);
    // display(butterscotch);
    // display(NoFlavour);
    intersection(vanilla, butterscotch);
    cout << "\n";
    onlyVanilla(vanilla, butterscotch);
    cout << "\n";
    onlyButterScotch(vanilla, butterscotch);
    cout << "\n";
    BothFlavours(vanilla, butterscotch);
    cout << "\n"; 
    Neither(students, vanilla, butterscotch);

    return 0;
}