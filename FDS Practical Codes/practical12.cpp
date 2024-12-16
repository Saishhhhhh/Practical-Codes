// Assignment No-12

// Aim: To illustrate the concept of double-ended queue (deque).

// Problem Statement: A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. Obtain a data representation mapping a deque into a one- dimensional array. Write C++ program to simulate deque with functions to add and delete elements from either end of the deque

#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front, rear, size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void addFront(int element) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = element;
        cout << "Added " << element << " at the front." << endl;
    }

    void addBack(int element) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
        cout << "Added " << element << " at the back." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        int deletedElement = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        cout << "Deleted " << deletedElement << " from the front." << endl;
    }

    void deleteBack() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        int deletedElement = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        cout << "Deleted " << deletedElement << " from the back." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements are: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Deque dq(5);

    dq.addBack(10);
    dq.addBack(20);
    dq.addFront(30);
    dq.addFront(40);

    dq.display();

    dq.deleteFront();
    dq.deleteBack();

    dq.display();

    dq.addBack(50);
    dq.addFront(60);

    dq.display();

    return 0;
}
