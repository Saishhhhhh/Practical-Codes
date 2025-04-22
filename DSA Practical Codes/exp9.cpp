// Problem Statement:
// Implement a Dictionary using AVL Tree (Height Balanced Binary Search Tree) with the following operations:
// 1. Add new keywords and their meanings
// 2. Delete keywords
// 3. Update values of any entry
// 4. Display data sorted in ascending/descending order
// 5. Search for keywords
// The AVL tree ensures O(log n) time complexity for all operations by maintaining balance.

#include <iostream>
#include <string>
using namespace std;

// Node structure for AVL Tree
class AVLNode {
public:
    string keyword;     // The word to be stored
    string meaning;     // The meaning of the word
    AVLNode* left;      // Pointer to left child
    AVLNode* right;     // Pointer to right child
    int height;         // Height of the node for balance factor

    // Constructor
    AVLNode(string key = "", string mean = "") {
        keyword = key;
        meaning = mean;
        left = NULL;
        right = NULL;
        height = 1;  // New node is initially at height 1
    }
};

class AVLDictionary {
private:
    AVLNode* root;  // Root of the AVL tree

    // Helper function to get height of a node
    int getHeight(AVLNode* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    // Helper function to get balance factor of a node
    int getBalanceFactor(AVLNode* node) {
        if (node == NULL) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Helper function to update height of a node
    void updateHeight(AVLNode* node) {
        if (node == NULL) return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Right rotation (LL case)
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Left rotation (RR case)
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Insert a new node into the AVL tree
    AVLNode* insertNode(AVLNode* node, string key, string meaning) {
        // Perform normal BST insertion
        if (node == NULL) {
            return new AVLNode(key, meaning);
        }

        if (key < node->keyword) {
            node->left = insertNode(node->left, key, meaning);
        } else if (key > node->keyword) {
            node->right = insertNode(node->right, key, meaning);
        } else {
            cout << "Keyword already exists!" << endl;
            return node;
        }

        // Update height of this ancestor node
        updateHeight(node);

        // Get the balance factor to check if this node became unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->keyword) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->keyword) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->keyword) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->keyword) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Find the node with minimum value in a subtree
    AVLNode* findMinNode(AVLNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Delete a node from the AVL tree
    AVLNode* deleteNode(AVLNode* root, string key) {
        if (root == NULL) {
            cout << "Keyword not found!" << endl;
            return root;
        }

        // Perform standard BST delete
        if (key < root->keyword) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->keyword) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == NULL || root->right == NULL) {
                AVLNode* temp = root->left ? root->left : root->right;

                // No child case
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else {
                    // One child case
                    *root = *temp;
                }
                delete temp;
            } else {
                // Node with two children
                AVLNode* temp = findMinNode(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        // If the tree had only one node then return
        if (root == NULL) return root;

        // Update height of the current node
        updateHeight(root);

        // Get the balance factor to check if this node became unbalanced
        int balance = getBalanceFactor(root);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        }

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Helper function for inorder traversal (ascending order)
    void inorderTraversal(AVLNode* node) {
        if (node == NULL) return;
        inorderTraversal(node->left);
        cout << node->keyword << " : " << node->meaning << endl;
        inorderTraversal(node->right);
    }

    // Helper function for reverse inorder traversal (descending order)
    void reverseInorderTraversal(AVLNode* node) {
        if (node == NULL) return;
        reverseInorderTraversal(node->right);
        cout << node->keyword << " : " << node->meaning << endl;
        reverseInorderTraversal(node->left);
    }

    // Helper function to search for a keyword
    bool searchKeyword(AVLNode* node, string key) {
        if (node == NULL) return false;
        if (key == node->keyword) return true;
        if (key < node->keyword) return searchKeyword(node->left, key);
        return searchKeyword(node->right, key);
    }

public:
    // Constructor
    AVLDictionary() {
        root = NULL;
    }

    // Function to add a new keyword
    void addKeyword() {
        string key, meaning;
        cout << "Enter the keyword: ";
        cin >> key;
        cout << "Enter the meaning: ";
        cin.ignore();
        getline(cin, meaning);
        root = insertNode(root, key, meaning);
        cout << "Keyword added successfully!" << endl;
    }

    // Function to delete a keyword
    void deleteKeyword() {
        string key;
        cout << "Enter the keyword to delete: ";
        cin >> key;
        root = deleteNode(root, key);
    }

    // Function to display keywords in ascending order
    void displayAscending() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        cout << "\nDictionary (Ascending Order):" << endl;
        cout << "------------------------" << endl;
        inorderTraversal(root);
    }

    // Function to display keywords in descending order
    void displayDescending() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        cout << "\nDictionary (Descending Order):" << endl;
        cout << "------------------------" << endl;
        reverseInorderTraversal(root);
    }

    // Function to search for a keyword
    void searchKeyword() {
        string key;
        cout << "Enter the keyword to search: ";
        cin >> key;
        if (searchKeyword(root, key)) {
            cout << "Keyword found in the dictionary!" << endl;
        } else {
            cout << "Keyword not found!" << endl;
        }
    }
};

int main() {
    AVLDictionary dict;
    int choice;

    cout << "========== DICTIONARY USING AVL TREE ==========" << endl;
    cout << "This program implements a dictionary using AVL tree" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add a new keyword" << endl;
        cout << "2. Delete a keyword" << endl;
        cout << "3. Display keywords in ascending order" << endl;
        cout << "4. Display keywords in descending order" << endl;
        cout << "5. Search for a keyword" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dict.addKeyword();
                break;
            case 2:
                dict.deleteKeyword();
                break;
            case 3:
                dict.displayAscending();
                break;
            case 4:
                dict.displayDescending();
                break;
            case 5:
                dict.searchKeyword();
                break;
            case 6:
                cout << "Thank you for using the dictionary!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

// Sample Input Sequence:

// 1. Add Keywords (Option 1)
//    Enter keyword: apple
//    Enter meaning: A round fruit with red or green skin
//    Enter keyword: banana
//    Enter meaning: A long curved fruit with yellow skin
//    Enter keyword: cherry
//    Enter meaning: A small round red fruit

// 2. Display in Ascending Order (Option 3)
//    (Output will show: apple, banana, cherry)

// 3. Display in Descending Order (Option 4)
//    (Output will show: cherry, banana, apple)

// 4. Search for a Keyword (Option 5)
//    Enter keyword: banana
//    (Output: Keyword found in the dictionary!)

// 5. Delete a Keyword (Option 2)
//    Enter keyword: banana
//    (Output: Keyword deleted successfully)

// 6. Display Again (Option 3)
//    (Output will show: apple, cherry)