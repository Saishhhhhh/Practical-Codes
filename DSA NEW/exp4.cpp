// Problem Statement:
// A Dictionary stores keywords and its meanings. Provide facility for:
// 1. Adding new keywords
// 2. Deleting keywords
// 3. Updating values of any entry
// 4. Displaying whole data sorted in ascending/descending order
// 5. Finding maximum comparisons required for finding any keyword
// Implementation using Binary Search Tree

#include <iostream>
#include <string>
using namespace std;

// BST Node for Dictionary
class Node {
public:
    string word;
    string meaning;
    Node *left, *right;
    
    Node(string w, string m) {
        word = w;
        meaning = m;
        left = NULL;
        right = NULL;
    }
};

class Dictionary {
private:
    Node *root;
    int maxComparisons;
    
    // Helper function for tree traversal
    void traverse(Node *node, bool ascending) {
        if (!node) return;
        
        if (ascending) {
            traverse(node->left, ascending);
            cout << node->word << " : " << node->meaning << endl;
            traverse(node->right, ascending);
        } else {
            traverse(node->right, ascending);
            cout << node->word << " : " << node->meaning << endl;
            traverse(node->left, ascending);
        }
    }
    
    // Recursive function to find min node
    Node* findMin(Node *node) {
        if (node->left) {
            return findMin(node->left);
        } else {
            return node;
        }
    }
    
    // Recursive delete helper
    Node* deleteNode(Node *root, string key) {
        if (!root) return NULL;
        
        if (key < root->word)
            root->left = deleteNode(root->left, key);
        else if (key > root->word)
            root->right = deleteNode(root->right, key);
        else {
            //Node is found here

            
            // Node with only one child or no child
            if (!root->left) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            // Node with two children
            Node *temp = findMin(root->right);
            root->word = temp->word;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->word);
        }
        return root;
    }

public:
    Dictionary() {
        root = NULL;
        maxComparisons = 0;
    }
    
    // Add a new word
    void addWord() {
        string word, meaning;
        
        cout << "Enter the word: ";
        cin >> word;
        cout << "Enter the meaning: ";
        cin.ignore();
        getline(cin, meaning);
        
        if (!root) {
            root = new Node(word, meaning);
            cout << "Word added successfully!" << endl;
            return;
        }
        
        Node *current = root;
        Node *parent = NULL;
        
        while (current) {
            parent = current;
            if (word < current->word)
                current = current->left;
            else if (word > current->word)
                current = current->right;
            else {
                cout << "Word already exists!" << endl;
                return;
            }
        }
        
        if (word < parent->word)
            parent->left = new Node(word, meaning);
        else
            parent->right = new Node(word, meaning);
            
        cout << "Word added successfully!" << endl;
    }
    
    // Search for a word
    void searchWord() {
        if (!root) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        
        string word;
        cout << "Enter the word to search: ";
        cin >> word;
        
        Node *current = root;
        int comparisons = 0;
        
        while (current) {
            comparisons++;
            if (word == current->word) {
                cout << "Word found!\n" << current->word << " : " << current->meaning << endl;
                cout << "Number of comparisons: " << comparisons << endl;
                if (comparisons > maxComparisons) {
                    maxComparisons = comparisons;
                }
                return;
            }
            
            if (word < current->word) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        cout << "Word not found!\nNumber of comparisons: " << comparisons << endl;
    }
    
    // Update a word's meaning
    void updateWord() {
        if (!root) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        
        string word, newMeaning;
        cout << "Enter the word to update: ";
        cin >> word;
        
        Node *current = root;
        
        while (current) {
            if (word == current->word) {
                cout << "Current meaning: " << current->meaning << endl;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, newMeaning);
                current->meaning = newMeaning;
                cout << "Meaning updated successfully!" << endl;
                return;
            }
            
            if (word < current->word) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        cout << "Word not found in the dictionary!" << endl;
    }
    
    // Delete a word
    void deleteWord() {
        if (!root) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        
        string word;
        cout << "Enter the word to delete: ";
        cin >> word;
        
        // Check if word exists first
        Node *current = root;
        bool found = false;
        
        while (current) {
            if (word == current->word) {
                found = true;
                break;
            }
            
            if (word < current->word) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (!found) {
            cout << "Word not found in the dictionary!" << endl;
            return;
        }
        
        // Delete word
        root = deleteNode(root, word);
        cout << "Word deleted successfully!" << endl;
    }
    
    // Display words in order
    void display(bool ascending) {
        if (!root) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        
        cout << "\nDictionary (";
        if (ascending) {
            cout << "Ascending";
        } else {
            cout << "Descending";
        }
        cout << " Order):" << endl;
        cout << "------------------------" << endl;
        traverse(root, ascending);
    }
};

int main() {
    Dictionary dict;
    int choice;
    
    cout << "=== DICTIONARY USING BST ===" << endl;
    
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add word\n2. Search word\n3. Update word\n"
             << "4. Delete word\n5. Display ascending\n6. Display descending\n"
             << "7. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: dict.addWord(); break;
            case 2: dict.searchWord(); break;
            case 3: dict.updateWord(); break;
            case 4: dict.deleteWord(); break;
            case 5: dict.display(true); break;
            case 6: dict.display(false); break;
            case 7: cout << "Thank you for using the dictionary!" << endl; return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}

// Sample Input Sequence:

// 1. Add Words (Option 2)
//    2
//    Enter new Word: apple
//    Enter meaning: A round fruit with red or green skin

// 2. Add More Words
//    2
//    Enter new Word: banana
//    Enter meaning: A long curved fruit with yellow skin

// 3. Add Another Word
//    2
//    Enter new Word: cherry
//    Enter meaning: A small round red fruit

// 4. View Words in Ascending Order (Option 1, then 1)
//    1
//    1
//    (Output will show: apple, banana, cherry)

// 5. View Words in Descending Order (Option 1, then 2)
//    1
//    2
//    (Output will show: cherry, banana, apple)

// 6. Search for a Word (Option 3)
//    3
//    Enter key to search: banana
//    (Output will show: banana = A long curved fruit with yellow skin)
//    (And: 1 entries found!)

// 7. Update a Word (Option 4)
//    4
//    Enter key to update: apple
//    (Shows current meaning)
//    Enter new meaning: A common fruit that grows on trees

// 8. View Updated Dictionary (Option 1, then 1)
//    1
//    1
//    (Output will show updated meanings)

// 9. Exit Program (Option 5)
//    5