// Problem Statement:
// Given a sequence of n sorted keys k1 < k2 < ... < kn, with a search probability pi for each key ki,
// build the Binary Search Tree that has the least search cost given the access probability for each key.
// This is known as the Optimal Binary Search Tree (OBST) problem.

#include <iostream>
#include <iomanip>
using namespace std;

class OptimalBST {
private:
    // Constants for array sizes
    static const int MAX_NODES = 20;

    // Arrays to store probabilities and costs
    float successProb[MAX_NODES];      // p[i] - probability of successful search for key i
    float failProb[MAX_NODES];         // q[i] - probability of unsuccessful search for interval i
    float weight[MAX_NODES][MAX_NODES]; // w[i][j] - sum of probabilities for subtree i to j
    float cost[MAX_NODES][MAX_NODES];   // c[i][j] - minimum cost for subtree i to j
    int root[MAX_NODES][MAX_NODES];     // r[i][j] - root of optimal subtree i to j
    int numNodes;                       // Number of nodes in the tree

    // Function to construct the optimal BST
    void constructOptimalBST() {
        // Initialize for subtrees of size 0
        for (int i = 0; i < numNodes; i++) {
            cost[i][i] = 0.0;
            root[i][i] = 0;
            weight[i][i] = failProb[i];
        }

        // Initialize for subtrees of size 1
        for (int i = 0; i < numNodes; i++) {
            int j = i + 1;
            weight[i][j] = weight[i][i] + successProb[j] + failProb[j];
            cost[i][j] = weight[i][j];
            root[i][j] = j;
        }

        // Construct optimal BST for subtrees of size 2 to n
        for (int size = 2; size <= numNodes; size++) {
            for (int i = 0; i <= numNodes - size; i++) {
                int j = i + size;
                weight[i][j] = weight[i][j-1] + successProb[j] + failProb[j];
                cost[i][j] = 9999; // Initialize with a large value

                // Try all possible roots and find the one with minimum cost
                for (int k = i + 1; k <= j; k++) {
                    float currentCost = cost[i][k-1] + cost[k][j];
                    if (currentCost < cost[i][j]) {
                        cost[i][j] = currentCost;
                        root[i][j] = k;
                    }
                }
                cost[i][j] += weight[i][j];
            }
        }
    }

    // Function to print the structure of the optimal BST
    void printTreeStructure(int left, int right) {
        if (left >= right) return;

        int currentRoot = root[left][right];
        
        // Print left child
        if (root[left][currentRoot-1] != 0) {
            cout << "\nLeft child of " << currentRoot << " is " << root[left][currentRoot-1];
        }

        // Print right child
        if (root[currentRoot][right] != 0) {
            cout << "\nRight child of " << currentRoot << " is " << root[currentRoot][right];
        }

        // Recursively print left and right subtrees
        printTreeStructure(left, currentRoot-1);
        printTreeStructure(currentRoot, right);
    }

public:
    // Constructor
    OptimalBST() {
        numNodes = 0;
    }

    // Function to get input from user
    void getInput() {
        cout << "\n========== OPTIMAL BINARY SEARCH TREE ==========" << endl;
        cout << "This program constructs an optimal binary search tree" << endl;
        cout << "given the probabilities of successful and unsuccessful searches." << endl;

        cout << "\nEnter the number of nodes: ";
        cin >> numNodes;

        cout << "\nEnter the probabilities for successful search (p[i]):" << endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 1; i <= numNodes; i++) {
            cout << "p[" << i << "]: ";
            cin >> successProb[i];
        }

        cout << "\nEnter the probabilities for unsuccessful search (q[i]):" << endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 0; i <= numNodes; i++) {
            cout << "q[" << i << "]: ";
            cin >> failProb[i];
        }
    }

    // Function to build and display the optimal BST
    void buildAndDisplay() {
        constructOptimalBST();

        cout << "\nOptimal Binary Search Tree Details:" << endl;
        cout << "---------------------------------" << endl;
        cout << "Total weight: " << weight[0][numNodes] << endl;
        cout << "Minimum cost: " << cost[0][numNodes] << endl;
        cout << "Root of the tree: " << root[0][numNodes] << endl;

        cout << "\nTree Structure:" << endl;
        cout << "--------------" << endl;
        printTreeStructure(0, numNodes);
        cout << endl;
    }
};

int main() {
    OptimalBST tree;
    tree.getInput();
    tree.buildAndDisplay();
    return 0;
}

// Sample Input:
// Number of nodes: 4
//
// Successful search probabilities (p[i]):
// p[1]: 0.3
// p[2]: 0.2
// p[3]: 0.1
// p[4]: 0.2
//
// Unsuccessful search probabilities (q[i]):
// q[0]: 0.1
// q[1]: 0.1
// q[2]: 0.1
// q[3]: 0.1
// q[4]: 0.1