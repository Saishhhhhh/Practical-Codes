/*
Aim: To illustrate the concept of double-ended queue (deque).

Problem Statement: A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. 
Obtain a data representation mapping a deque into a one- dimensional array. 
Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.
*/

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
        return (front == 0 && rear == size - 1) || (rear + 1 == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int data) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at front.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = data;
        cout << "Inserted " << data << " at front.\n";
    }

    void insertRear(int data) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at rear.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = data;
        cout << "Inserted " << data << " at rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        cout << "Deleted " << arr[front] << " from front.\n";
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        cout << "Deleted " << arr[rear] << " from rear.\n";
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the deque: ";
    cin >> size;

    Deque deque(size);

    do {
        cout << "\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                deque.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                deque.insertRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

/*
    INPUT   

Enter the size of the deque: 5

1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display
6. Exit

Enter your choice: 1
Enter value to insert at front: 10
Inserted 10 at front.

Enter your choice: 2
Enter value to insert at rear: 20
Inserted 20 at rear.

Enter your choice: 5
Deque elements: 10 20

Enter your choice: 3
Deleted 10 from front.

Enter your choice: 5
Deque elements: 20

Enter your choice: 6
Exiting...


*/
