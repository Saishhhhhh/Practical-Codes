// Assignment No - 13

// Aim: To illustrate the concept of circular queue.

// Problem Statement: Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array.

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int maxSize;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        maxSize = size;
        queue = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (front == (rear + 1) % maxSize);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept new order.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % maxSize;
        queue[rear] = order;
        cout << "Order " << order << " added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve.\n";
            return;
        }

        cout << "Order " << queue[front] << " served.\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to display.\n";
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    CircularQueue pizzaQueue(maxOrders);

    pizzaQueue.enqueue(101);
    pizzaQueue.enqueue(102);
    pizzaQueue.enqueue(103);

    cout << "\nDisplaying all orders:\n";
    pizzaQueue.display();

    cout << "\nServing orders:\n";
    pizzaQueue.dequeue();
    pizzaQueue.dequeue();

    cout << "\nDisplaying remaining orders:\n";
    pizzaQueue.display();

    pizzaQueue.enqueue(104);
    pizzaQueue.enqueue(105);

    cout << "\nDisplaying all orders after adding new ones:\n";
    pizzaQueue.display();

    return 0;
}
