// Assignment No - 11

// Aim: To illustrate the concept of queue.

// Problem Statement: Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue.

#include<iostream>
using namespace std;

struct Node{
    string jobName;
    Node *next;

    Node(string jobName1, Node *next1){
        jobName = jobName1;
        next = next1;
    }

    Node(string jobName1){
        jobName = jobName1;
        next = nullptr;
    }
};

bool isEmpty(Node *head){

    if(head == NULL){
        return true;   
    }
    return false;
}  

Node *add(Node *head, string jobName){

    Node *newNode = new Node(jobName);

    if (isEmpty(head)) {
 
        return newNode;    
    }

    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;

    cout << newNode->jobName << " job has been added" << endl;

    return head;
}

Node *del(Node *head){

    if (isEmpty(head)) {
        cout << "queue is empty" << endl; 
        return head;    
    }
    
    cout << head->jobName << " is deleted";

    Node *temp = head;
    head=temp->next;
    temp->next = nullptr;
    delete temp;

    return head;
}

void getFront(Node *head){

    if (isEmpty(head)) {
        cout << "queue is empty" << endl;
        return;    
    }

    cout << head->jobName << " is the first job" << "\n";
} 

void display(Node *head){

    if(isEmpty(head) == true){
        cout << "The queue is empty";
        return;    
    }

    Node *temp = head;

    while(temp!=NULL){
        cout << temp->jobName << "\n";
        temp = temp->next;
    }

    cout << endl;
}

int main(){
    Node* job = nullptr; // Initialize the job queue

    cout << "Adding jobs to the queue...\n";
    job = add(job, "Compile Code");
    job = add(job, "Debug Code");
    job = add(job, "Run Tests");
    job = add(job, "Deploy Application");

    cout << "\nDisplaying all jobs in the queue:\n";
    display(job);

    cout << "\nGetting the front job:\n";
    getFront(job);

    cout << "\nDeleting jobs one by one:\n";
    while (!isEmpty(job)) {
        job = del(job);
        cout << endl; // Print a new line for better readability
    }

    cout << "\nAttempting to display jobs after queue is empty:\n";
    display(job);

    return 0;
}