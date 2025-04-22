// Problem Statement:
// You have a business with several offices; you want to lease phone lines to connect them up with each other;
// and the phone company charges different amounts of money to connect different pairs of cities.
// You want a set of lines that connects all your offices with a minimum total cost.

#include<iostream>
using namespace std;

// Constants for better readability
#define MAX_OFFICES 20
#define INFINITY 999

class MinimumSpanningTree {
private:
    // Graph representation using adjacency matrix
    int graph[MAX_OFFICES][MAX_OFFICES];  // Stores connection costs between offices
    int numOffices;                       // Total number of offices
    int numConnections;                   // Total number of possible connections
    bool visited[MAX_OFFICES];            // Tracks which offices are already connected

public:
    // Function to get input from user
    void getInput() {
        cout << "\nEnter the number of offices: ";
        cin >> numOffices;

        // Initialize the graph with no connections (INFINITY cost)
        for(int i = 0; i < numOffices; i++) {
            visited[i] = false;  // No office is visited initially
            for(int j = 0; j < numOffices; j++) {
                graph[i][j] = INFINITY;  // No connection means infinite cost
            }
        }

        cout << "Enter the number of possible connections: ";
        cin >> numConnections;

        // Get connection details from user
        for(int i = 0; i < numConnections; i++) {
            int office1, office2, cost;
            cout << "\nConnection " << (i+1) << ":" << endl;
            cout << "Enter first office number: ";
            cin >> office1;
            cout << "Enter second office number: ";
            cin >> office2;
            cout << "Enter connection cost: ";
            cin >> cost;

            // Store the connection cost in both directions (undirected graph)
            graph[office1-1][office2-1] = cost;
            graph[office2-1][office1-1] = cost;
        }
    }

    // Function to find minimum spanning tree using Prim's algorithm
    void findMinimumSpanningTree() {
        int totalCost = 0;
        visited[0] = true;  // Start with the first office

        cout << "\nMinimum Cost Connections:" << endl;
        cout << "------------------------" << endl;

        // We need (numOffices-1) connections to connect all offices
        for(int connections = 0; connections < numOffices - 1; connections++) {
            int minCost = INFINITY;
            int office1 = -1, office2 = -1;

            // Find the minimum cost connection between visited and unvisited offices
            for(int i = 0; i < numOffices; i++) {
                if(visited[i]) {  // If office i is already connected
                    for(int j = 0; j < numOffices; j++) {
                        if(!visited[j] && graph[i][j] < minCost) {  // If office j is not connected and has lower cost
                            minCost = graph[i][j];
                            office1 = i;
                            office2 = j;
                        }
                    }
                }
            }

            // Add the minimum cost connection
            visited[office2] = true;
            totalCost += minCost;
            cout << "Office " << (office1 + 1) << " -> Office " << (office2 + 1) 
                 << " : Cost = " << minCost << endl;
        }

        cout << "\nTotal Minimum Cost to connect all offices: " << totalCost << endl;
    }
};

int main() {
    cout << "========== MINIMUM COST OFFICE CONNECTIONS ==========" << endl;
    cout << "This program finds the minimum cost to connect all offices" << endl;
    cout << "using Prim's Minimum Spanning Tree algorithm." << endl;

    MinimumSpanningTree mst;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Enter office connection details" << endl;
        cout << "2. Find minimum cost connections" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                mst.getInput();
                break;
            case 2:
                mst.findMinimumSpanningTree();
                break;
            case 3:
                cout << "Thank you for using the program!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 3);

    return 0;
}

// 1  (Choose "Enter office connection details")

// 5  (Enter number of offices)

// 7  (Enter number of possible connections)

// Connection 1:
// 1  (First office number)
// 2  (Second office number)
// 10 (Connection cost)

// Connection 2:
// 1  (First office number)
// 3  (Second office number)
// 20 (Connection cost)

// Connection 3:
// 2  (First office number)
// 3  (Second office number)
// 30 (Connection cost)

// Connection 4:
// 2  (First office number)
// 4  (Second office number)
// 5  (Connection cost)

// Connection 5:
// 3  (First office number)
// 4  (Second office number)
// 15 (Connection cost)

// Connection 6:
// 3  (First office number)
// 5  (Second office number)
// 25 (Connection cost)

// Connection 7:
// 4  (First office number)
// 5  (Second office number)
// 8  (Connection cost)

// 2  (Choose "Find minimum cost connections")

// 3  (Choose "Exit")