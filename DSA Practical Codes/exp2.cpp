// Problem Statement:
// To create ADT that implements the SET concept with the following operations:
// a. Add (newElement) - Place a value into the set
// b. Remove (element) - Remove the value
// c. Contains (element) - Return true if element is in collection
// d. Size () - Return number of values in collection
// e. Intersection of two sets
// f. Union of two sets
// g. Difference between two sets
// h. Subset

#include <iostream>
#include <list>
using namespace std;

class Set {
private:
    list<int> setA;    // First set
    list<int> setB;    // Second set
    list<int> result;  // Temporary list for operations

public:
    // Function to initialize both sets
    void initializeSets() {
        int sizeA, sizeB, element;
        
        // Initialize Set A
        cout << "\nSET A:" << endl;
        cout << "How many elements do you want to add in Set A: ";
        cin >> sizeA;
        cout << "Enter elements for Set A:" << endl;
        for (int i = 0; i < sizeA; i++) {
            cin >> element;
            setA.push_back(element);
        }

        // Initialize Set B
        cout << "\nSET B:" << endl;
        cout << "How many elements do you want to add in Set B: ";
        cin >> sizeB;
        cout << "Enter elements for Set B:" << endl;
        for (int i = 0; i < sizeB; i++) {
            cin >> element;
            setB.push_back(element);
        }
    }

    // Function to add an element to a set
    void addElement() {
        char setChoice;
        int element;
        
        cout << "In which set do you want to add element (A/B): ";
        cin >> setChoice;
        
        cout << "Enter the element: ";
        cin >> element;

        if (setChoice == 'A' || setChoice == 'a') {
            setA.push_back(element);
            cout << "Element " << element << " added to Set A" << endl;
        }
        else if (setChoice == 'B' || setChoice == 'b') {
            setB.push_back(element);
            cout << "Element " << element << " added to Set B" << endl;
        }
        else {
            cout << "Invalid set choice!" << endl;
        }
    }

    // Function to display both sets
    void displaySets() {
        cout << "\nSet A: { ";
        for (list<int>::iterator it = setA.begin(); it != setA.end(); it++) {
            cout << *it << " ";
        }
        cout << "}" << endl;

        cout << "Set B: { ";
        for (list<int>::iterator it = setB.begin(); it != setB.end(); it++) {
            cout << *it << " ";
        }
        cout << "}" << endl;
    }

    // Function to search for an element in both sets
    void searchElement(int element) {
        bool found = false;
        
        // Search in Set A
        for (list<int>::iterator it = setA.begin(); it != setA.end(); it++) {
            if (*it == element) {
                cout << "Element " << element << " found in Set A" << endl;
                found = true;
                break;
            }
        }

        // Search in Set B
        for (list<int>::iterator it = setB.begin(); it != setB.end(); it++) {
            if (*it == element) {
                cout << "Element " << element << " found in Set B" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Element " << element << " not found in either set" << endl;
        }
    }

    // Function to delete an element from both sets
    void deleteElement(int element) {
        bool deleted = false;
        
        // Delete from Set A
        setA.remove(element);
        
        // Delete from Set B
        setB.remove(element);
        
        cout << "Element " << element << " deleted from both sets" << endl;
    }

    // Function to find union of two sets
    void findUnion() {
        result.clear();
        
        // Add all elements from Set A
        for (list<int>::iterator it = setA.begin(); it != setA.end(); it++) {
            result.push_back(*it);
        }
        
        // Add elements from Set B that are not in Set A
        for (list<int>::iterator itB = setB.begin(); itB != setB.end(); itB++) {
            bool found = false;
            for (list<int>::iterator itA = setA.begin(); itA != setA.end(); itA++) {
                if (*itB == *itA) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back(*itB);
            }
        }

        cout << "Union of Set A and Set B: { ";
        for (list<int>::iterator it = result.begin(); it != result.end(); it++) {
            cout << *it << " ";
        }
        cout << "}" << endl;
    }

    // Function to find intersection of two sets
    void findIntersection() {
        result.clear();
        
        // Find common elements
        for (list<int>::iterator itA = setA.begin(); itA != setA.end(); itA++) {
            for (list<int>::iterator itB = setB.begin(); itB != setB.end(); itB++) {
                if (*itA == *itB) {
                    result.push_back(*itA);
                    break;
                }
            }
        }

        if (result.empty()) {
            cout << "No common elements in Set A and Set B" << endl;
        }
        else {
            cout << "Intersection of Set A and Set B: { ";
            for (list<int>::iterator it = result.begin(); it != result.end(); it++) {
                cout << *it << " ";
            }
            cout << "}" << endl;
        }
    }

    // Function to find difference between two sets (A - B)
    void findDifference() {
        result.clear();
        
        // Find elements in A that are not in B
        for (list<int>::iterator itA = setA.begin(); itA != setA.end(); itA++) {
            bool found = false;
            for (list<int>::iterator itB = setB.begin(); itB != setB.end(); itB++) {
                if (*itA == *itB) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back(*itA);
            }
        }

        if (result.empty()) {
            cout << "Set A is a subset of Set B" << endl;
        }
        else {
            cout << "Difference (Set A - Set B): { ";
            for (list<int>::iterator it = result.begin(); it != result.end(); it++) {
                cout << *it << " ";
            }
            cout << "}" << endl;
        }
    }
};

int main() {
    Set mySet;
    int choice, element;
    
    cout << "========== SET OPERATIONS ==========" << endl;
    cout << "This program implements various operations on sets" << endl;
    
    // Initialize sets first
    mySet.initializeSets();

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. Display Sets" << endl;
        cout << "5. Find Union" << endl;
        cout << "6. Find Intersection" << endl;
        cout << "7. Find Difference" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mySet.addElement();
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                mySet.deleteElement(element);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                mySet.searchElement(element);
                break;
            case 4:
                mySet.displaySets();
                break;
            case 5:
                mySet.findUnion();
                break;
            case 6:
                mySet.findIntersection();
                break;
            case 7:
                mySet.findDifference();
                break;
            case 8:
                cout << "Thank you for using the program!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

// SET A:
// How many elements do you want to add in Set A: 3
// Enter elements for Set A:
// 1
// 2
// 3

// SET B:
// How many elements do you want to add in Set B: 4
// Enter elements for Set B:
// 2
// 3
// 4
// 5