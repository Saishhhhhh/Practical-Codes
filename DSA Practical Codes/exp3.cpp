// Problem Statement:
// A book consists of chapters, chapters consist of sections and sections consist of
// subsections. Construct a tree and print the nodes. Find the time and space requirements of your
// method.

#include <iostream>
using namespace std;

// Node structure for the tree
struct TreeNode {
    int data;           // Data stored in the node
    TreeNode *left;     // Pointer to left child
    TreeNode *right;    // Pointer to right child
    int leftThread;     // Flag for left thread (0 = child, 1 = thread)
    int rightThread;    // Flag for right thread (0 = child, 1 = thread)
};

class ThreadedBinaryTree {
private:
    TreeNode *root;     // Root of the tree
    TreeNode *dummy;    // Dummy node for threading

    // Helper function to create a new node
    TreeNode* createNode() {
        TreeNode *newNode = new TreeNode;
        cout << "Enter the data for the node: ";
        cin >> newNode->data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leftThread = 0;
        newNode->rightThread = 0;
        return newNode;
    }

    // Helper function to find inorder predecessor
    TreeNode* findInorderPredecessor(TreeNode *current) {
        if (current->leftThread == 1) {
            return current->left;
        }
        current = current->left;
        while (current->rightThread == 1) {
            current = current->right;
        }
        return current;
    }

    // Helper function to find inorder successor
    TreeNode* findInorderSuccessor(TreeNode *current) {
        if (current->rightThread == 1) {
            return current->right;
        }
        current = current->right;
        while (current->leftThread == 1) {
            current = current->left;
        }
        return current;
    }

public:
    // Constructor
    ThreadedBinaryTree() {
        // Create dummy node
        dummy = new TreeNode;
        dummy->data = -1;
        dummy->left = dummy;
        dummy->right = dummy;
        dummy->leftThread = 0;
        dummy->rightThread = 0;
        root = NULL;
    }

    // Function to insert a new node
    void insertNode() {
        TreeNode *newNode = createNode();
        
        // If tree is empty
        if (root == NULL) {
            root = newNode;
            root->left = dummy;
            root->right = dummy;
            root->leftThread = 1;
            root->rightThread = 1;
            dummy->left = root;
            return;
        }

        // Find the appropriate position for the new node
        TreeNode *current = root;
        TreeNode *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (newNode->data < current->data) {
                if (current->leftThread == 0) {
                    current = current->left;
                }
                else {
                    break;
                }
            }
            else {
                if (current->rightThread == 0) {
                    current = current->right;
                }
                else {
                    break;
                }
            }
        }

        // Insert the new node
        if (newNode->data < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = 0;
            parent->left = newNode;
        }
        else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rightThread = 0;
            parent->right = newNode;
        }
    }

    // Function to display all nodes in inorder traversal
    void displayAllNodes() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        cout << "\nAll nodes in inorder traversal:" << endl;
        TreeNode *current = root;
        
        // Find the leftmost node
        while (current->leftThread == 0) {
            current = current->left;
        }

        // Traverse using threads
        while (current != dummy) {
            cout << current->data << " ";
            current = findInorderSuccessor(current);
        }
        cout << endl;
    }

    // Function to display threaded nodes
    void displayThreadedNodes() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        cout << "\nThreaded nodes:" << endl;
        displayThreadedNodesHelper(root);
        cout << endl;
    }

    // Helper function for displaying threaded nodes
    void displayThreadedNodesHelper(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        if (node->leftThread == 1 || node->rightThread == 1) {
            cout << node->data << " ";
        }

        if (node->leftThread == 0) {
            displayThreadedNodesHelper(node->left);
        }
        if (node->rightThread == 0) {
            displayThreadedNodesHelper(node->right);
        }
    }
};

int main() {
    ThreadedBinaryTree tree;
    int choice;

    cout << "========== THREADED BINARY TREE ==========" << endl;
    cout << "This program implements a threaded binary tree" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Display all nodes" << endl;
        cout << "3. Display threaded nodes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.insertNode();
                break;
            case 2:
                tree.displayAllNodes();
                break;
            case 3:
                tree.displayThreadedNodes();
                break;
            case 4:
                cout << "Thank you for using the program!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

// Sample Input Sequence:

// 1. Insert Data (10)
//    1
//    10

// 2. Insert Data (20)
//    1
//    20

// 3. Insert Data (5)
//    1
//    5

// 4. Insert Data (15)
//    1
//    15

// 5. Insert Data (25)
//    1
//    25

// 6. Display All Data
//    2

// 7. Display Threaded Nodes
//    3

// 8. Exit Program
//    4

// Expected Output:
// 1. After inserting all nodes, the tree structure will be:
//      10
//     /  \
//    5    20
//        /  \
//       15   25

// 2. When displaying all data (option 2), output will be:
//    5
//    10
//    15
//    20
//    25

// 3. When displaying threaded nodes (option 3), output will show:
//    thread are
//    5
//    15
//    25
