// Problem Statement:
// Convert a given binary tree into a threaded binary tree.
// A threaded binary tree is a binary tree where empty left/right pointers
// are replaced with threads that point to inorder predecessor/successor.
// This allows for efficient inorder traversal without using recursion or stack.

#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure for the threaded binary tree
struct TreeNode {
    int data;           // Data stored in the node
    TreeNode *left;     // Left child pointer
    TreeNode *right;    // Right child pointer
    bool leftThread;    // True if left pointer is a thread
    bool rightThread;   // True if right pointer is a thread
};

class ThreadedBinaryTree {
private:
    TreeNode *root;     // Root of the tree
    TreeNode *dummy;    // Dummy node for threading

    // Helper function to create a new node
    TreeNode* createNode(int data) {
        TreeNode *newNode = new TreeNode;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leftThread = false;
        newNode->rightThread = false;
        return newNode;
    }

    // Helper function to find inorder predecessor
    TreeNode* findInorderPredecessor(TreeNode *node) {
        if (node->leftThread) {
            return node->left;
        }
        TreeNode *temp = node->left;
        while (temp->rightThread == false && temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    // Helper function to find inorder successor
    TreeNode* findInorderSuccessor(TreeNode *node) {
        if (node->rightThread) {
            return node->right;
        }
        TreeNode *temp = node->right;
        while (temp->leftThread == false && temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

public:
    // Constructor
    ThreadedBinaryTree() {
        // Create dummy node
        dummy = new TreeNode;
        dummy->data = -1;
        dummy->left = dummy;
        dummy->right = dummy;
        dummy->leftThread = true;
        dummy->rightThread = true;
        root = NULL;
    }

    // Function to insert a new node
    void insertNode() {
        int data;
        cout << "Enter the data: ";
        cin >> data;

        TreeNode *newNode = createNode(data);

        // If tree is empty
        if (root == NULL) {
            root = newNode;
            root->left = dummy;
            root->right = dummy;
            root->leftThread = true;
            root->rightThread = true;
            dummy->left = root;
            return;
        }

        // Find the appropriate position for the new node
        TreeNode *current = root;
        TreeNode *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                if (current->leftThread == false) {
                    current = current->left;
                } else {
                    break;
                }
            } else if (data > current->data) {
                if (current->rightThread == false) {
                    current = current->right;
                } else {
                    break;
                }
            } else {
                cout << "Duplicate data not allowed!" << endl;
                return;
            }
        }

        // Insert the new node
        if (data < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = false;
            parent->left = newNode;
        } else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rightThread = false;
            parent->right = newNode;
        }
    }

    // Function to display all nodes in inorder traversal
    void displayAllNodes() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        cout << "\nInorder Traversal:" << endl;
        TreeNode *current = root;
        
        // Find the leftmost node
        while (current->leftThread == false) {
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

        cout << "\nThreaded Nodes:" << endl;
        displayThreadedNodesHelper(root);
        cout << endl;
    }

private:
    // Helper function for displaying threaded nodes
    void displayThreadedNodesHelper(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        if (node->leftThread == false) {
            displayThreadedNodesHelper(node->left);
        }

        if (node->leftThread || node->rightThread) {
            cout << node->data << " ";
        }

        if (node->rightThread == false) {
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
        cout << "2. Display all nodes (inorder)" << endl;
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

// 1. Insert Nodes (Option 1)
//    1
//    Enter data: 50
//    1
//    Enter data: 30
//    1
//    Enter data: 70
//    1
//    Enter data: 20
//    1
//    Enter data: 40
//    1
//    Enter data: 60
//    1
//    Enter data: 80

// 2. Display All Nodes (Option 2)
//    2
//    (Output will show: 20 30 40 50 60 70 80)

// 3. Display Threaded Nodes (Option 3)
//    3
//    (Output will show threaded nodes)

// 4. Exit Program (Option 4)
//    4