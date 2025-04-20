# Data Structures and Algorithms Practical Experiments

This repository contains implementations of various data structures and algorithms experiments. Each experiment focuses on a specific problem and its solution using appropriate data structures.

## Experiment List

### Experiment 1: Telephone Book Database using Hash Table
**Problem Statement:** Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client's telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.

**Implementation:** Uses a hash table with linear probing for collision handling. The program allows adding, searching, updating, and deleting telephone records.

### Experiment 2: Set ADT Implementation
**Problem Statement:** Create an ADT that implements the SET concept with the following operations:
- Add (newElement) - Place a value into the set
- Remove (element) - Remove the value
- Contains (element) - Return true if element is in collection
- Size () - Return number of values in collection
- Iterator () - Return an iterator used to loop over collection
- Intersection of two sets
- Union of two sets
- Difference between two sets
- Subset

**Implementation:** Uses linked lists to implement set operations with all required functionality.

### Experiment 3: Book Chapter Tree Structure
**Problem Statement:** A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of the method.

**Implementation:** Uses a threaded binary tree to represent the book structure and implements various tree traversal methods.

### Experiment 4: Dictionary using Binary Search Tree
**Problem Statement:** A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/Descending order. Also find how many maximum comparisons may require for finding any keyword.

**Implementation:** Uses a Binary Search Tree to store and manage dictionary entries with all required operations.

### Experiment 5: Telephone Book using Hash Table (Alternative Implementation)
**Problem Statement:** Similar to Experiment 1, but with a different implementation approach using hash tables for telephone directory management.

**Implementation:** Alternative implementation of hash table-based telephone directory with different collision handling strategy.

### Experiment 6: Flight Path Graph
**Problem Statement:** There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph.

**Implementation:** Uses adjacency matrix representation to store flight paths and their costs between cities.

### Experiment 7: Minimum Cost Phone Line Connection
**Problem Statement:** You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost.

**Implementation:** Uses Prim's algorithm to find the minimum spanning tree for connecting offices with minimum cost.

### Experiment 8: Optimal Binary Search Tree
**Problem Statement:** Given sequence k = k1 <k2 < ... <kn of n sorted keys, with a search probability pi for each key ki. Build the Binary search tree that has the least search cost given the access Probability for each key?

**Implementation:** Implements dynamic programming solution to construct an optimal binary search tree based on given probabilities.

### Experiment 9: Dictionary using AVL Tree
**Problem Statement:** A Dictionary stores keywords & its meaning. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword.

**Implementation:** Uses AVL tree to maintain a balanced dictionary structure with all required operations.

### Experiment 10: Student Marks using Heap
**Problem Statement:** Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyse the algorithm.

**Implementation:** Uses a min-heap to store and manage student marks, allowing efficient retrieval of maximum and minimum marks.

### Experiment 11: Student Information System using Sequential Files
**Problem Statement:** Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular employee. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to maintain the data.

**Implementation:** Uses sequential file handling to maintain student records with operations for adding, deleting, searching, and updating records.

### Experiment 12: Employee Information System using Index Sequential Files
**Problem Statement:** Company maintains employee information as employee ID, name, designation and salary. Allow user to add, delete information of employee. Display information of particular employee. If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. Use index sequential file to maintain the data.

**Implementation:** Uses index sequential file handling to maintain employee records with operations for adding, deleting, and displaying employee information.

## How to Use
Each experiment is implemented in a separate C++ file (exp1.cpp through exp12.cpp). To run any experiment:
1. Compile the respective file using a C++ compiler
2. Run the executable
3. Follow the menu-driven interface to perform various operations

## Note
Each implementation includes detailed comments and sample input/output examples in the code files. 