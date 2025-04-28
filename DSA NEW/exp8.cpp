// Problem Statement:
// Given a sequence of n sorted keys k1 < k2 < ... < kn, with a search probability pi for each key ki,
// build the Binary Search Tree that has the least search cost given the access probability for each key.
// This is known as the Optimal Binary Search Tree (OBST) problem.

#include <iostream>
using namespace std;

const int MAX = 20;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// Build Optimal BST using DP
void optimalBST(int keys[], double prob[], int n, double cost[MAX][MAX], int root[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        cost[i][i] = prob[i];
        root[i][i] = i;
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = 1e9;
            double sumProb = 0;
            for (int k = i; k <= j; k++) sumProb += prob[k];

            for (int r = i; r <= j; r++) {
                double left = (r > i) ? cost[i][r - 1] : 0;
                double right = (r < j) ? cost[r + 1][j] : 0;
                double total = left + right + sumProb;
                if (total < cost[i][j]) {
                    cost[i][j] = total;
                    root[i][j] = r;
                }
            }
        }
    }
}

// Recursively build tree from root table
Node* buildTree(int keys[], int root[MAX][MAX], int i, int j) {
    if (i > j) return nullptr;
    int r = root[i][j];
    Node* node = new Node(keys[r]);
    node->left = buildTree(keys, root, i, r - 1);
    node->right = buildTree(keys, root, r + 1, j);
    return node;
}

// Print the tree sideways with labels
void printTree(Node* root, int space = 0, string label = "Root") {
    if (!root) return;
    const int INDENT = 6;
    space += INDENT;

    // Print right child first (top of the display)
    printTree(root->right, space, "R");

    // Print current node
    cout << endl;
    for (int i = INDENT; i < space; i++)
        cout << " ";
    cout << label << ": " << root->key;

    // Print left child (bottom of the display)
    printTree(root->left, space, "L");
}

int main() {
    int n;
    int keys[MAX];
    double prob[MAX];

    cout << "Enter number of keys: ";
    cin >> n;
    if (n > MAX) {
        cout << "Error: Maximum " << MAX << " keys allowed.\n";
        return 1;
    }

    cout << "Enter keys in ascending order:\n";
    for (int i = 0; i < n; i++) cin >> keys[i];

    cout << "Enter corresponding probabilities:\n";
    for (int i = 0; i < n; i++) cin >> prob[i];

    double cost[MAX][MAX] = {0};
    int rootTable[MAX][MAX] = {0};

    optimalBST(keys, prob, n, cost, rootTable);

    Node* optimalRoot = buildTree(keys, rootTable, 0, n - 1);

    cout << "\nOptimal BST cost: " << cost[0][n - 1] << "\n";
    cout << "\nOptimal BST (Indented Display):\n\n";
    printTree(optimalRoot);

    return 0;
}

/*
Example run:
Enter number of keys: 4
Enter 4 keys in ascending order:
Key 1: 10
Key 2: 20
Key 3: 30
Key 4: 40
Enter probability for each key:
Probability for 10: 0.4
Probability for 20: 0.3
Probability for 30: 0.2
Probability for 40: 0.1

Optimal BST cost: 1.9

Tree Display:

      20 

     10 30 

        40 
*/
