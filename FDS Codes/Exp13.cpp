/*
Aim: To illustrate the concept of circular queue.

Problem Statement: Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. 
Order once placed cannot be cancelled. 
Write C++ program to simulate the system using circular queue using array.
*/

#include <iostream>
using namespace std;

class PizzaOrderQueue {
private:
    int *orders;
    int front, rear, maxSize, count;

public:
    // Constructor to initialize the queue
    PizzaOrderQueue(int size) {
        maxSize = size;
        orders = new int[maxSize];
        front = -1;
        rear = -1;
        count = 0;
    }

    // Destructor to release allocated memory
    ~PizzaOrderQueue() {
        delete[] orders;
    }

    bool isFull() {
        return count == maxSize;
    }

    bool isEmpty() {
        return count == 0;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Order queue is full. Cannot place new order.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        orders[rear] = orderID;
        count++;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve. The queue is empty.\n";
            return;
        }
        cout << "Order " << orders[front] << " is served.\n";
        if (front == rear) {
            front = rear = -1;  // Reset the queue if it becomes empty
        } else {
            front = (front + 1) % maxSize;
        }
        count--;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }
        cout << "Current Orders: ";
        int i = front;
        do {
            cout << orders[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);
        cout << endl;
    }
};

int main() {
    int size, choice, orderID;
    cout << "Enter the maximum number of orders: ";
    cin >> size;

    PizzaOrderQueue queue(size);

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                queue.placeOrder(orderID);
                break;

            case 2:
                queue.serveOrder();
                break;

            case 3:
                queue.displayOrders();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


/*
    INPUT

Enter the maximum number of orders: 5

1. Place Order
2. Serve Order
3. Display Orders
4. Exit

Enter your choice: 1
Enter Order ID: 101
Order 101 placed successfully.

Enter your choice: 1
Enter Order ID: 102
Order 102 placed successfully.

Enter your choice: 3
Current Orders: 101 102

Enter your choice: 2
Order 101 is served.

Enter your choice: 3
Current Orders: 102

Enter your choice: 1
Enter Order ID: 103
Order 103 placed successfully.

Enter your choice: 4
Exiting...

*/