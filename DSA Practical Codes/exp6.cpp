// Problem Statement :
// There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
// The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent 
// this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or 
// use adjacency matrix representation of the graph. Justify the storage representation used.


#include<iostream>
#include<string.h>
using namespace std;

class flight {
public:
    int am[10][10];                  // Adjacency matrix for distances
    char city_index[10][20];          // Array for city names (fixed size to accommodate city names)
    flight();                         // Constructor
    int create();                     // Method to create adjacency matrix
    void display(int city_count);     // Method to display the adjacency matrix
};

flight::flight() {
    int i, j;
    // Initialize city_index with "xx" and am with 0
    for(i = 0; i < 10; i++) {
        strcpy(city_index[i], "xx");
    }
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            am[i][j] = 0;
        }
    }
}

int flight::create() {
    int city_count = 0, j, si, di, wt;
    char s[20], d[20], c;

    do {
        cout << "\n\tEnter Source City: ";
        cin >> s;
        cout << "\n\tEnter Destination City: ";
        cin >> d;

        // Check if source city already exists
        for(j = 0; j < 10; j++) {
            if(strcmp(city_index[j], s) == 0) break;
        }
        if(j == 10) {  // If source city doesn't exist, add it
            strcpy(city_index[city_count], s);
            city_count++;
        }

        // Check if destination city already exists
        for(j = 0; j < 10; j++) {
            if(strcmp(city_index[j], d) == 0) break;
        }
        if(j == 10) {  // If destination city doesn't exist, add it
            strcpy(city_index[city_count], d);
            city_count++;
        }

        // Get the distance (weight) between the source and destination cities
        cout << "\n\tEnter Distance From " << s << " And " << d << ": ";
        cin >> wt;

        // Assign the weight in the adjacency matrix
        for(j = 0; j < 10; j++) {
            if(strcmp(city_index[j], s) == 0) si = j;
            if(strcmp(city_index[j], d) == 0) di = j;
        }
        am[si][di] = wt;

        // Ask if the user wants to add more cities
        cout << "\n\tDo you want to add more cities (y/n): ";
        cin >> c;
    } while(c == 'y' || c == 'Y');

    return city_count;  // Return the count of cities
}

void flight::display(int city_count) {
    int i, j;
    cout << "\n\tDisplaying Adjacency Matrix:\n\t";

    // Display the city names as headers
    for(i = 0; i < city_count; i++) {
        cout << "\t" << city_index[i];
    }
    cout << "\n";

    // Display the adjacency matrix values
    for(i = 0; i < city_count; i++) {
        cout << "\t" << city_index[i];
        for(j = 0; j < city_count; j++) {
            cout << "\t" << am[i][j];
        }
        cout << "\n";
    }
}

int main() {
    flight f;
    int n, city_count;
    char c;

    do {
        cout << "\nName: Anjali Shirke\tBatch: B1\tRoll No. 23207\n\t*** Flight Main Menu *****";
        cout << "\n\t1. Create\n\t2. Adjacency Matrix\n\t3. Exit";
        cout << "\n\tEnter your choice: ";
        cin >> n;

        switch(n) {
            case 1:
                city_count = f.create();  // Create adjacency matrix and get city count
                break;
            case 2:
                f.display(city_count);   // Display the adjacency matrix
                break;
            case 3:
                return 0;                 // Exit the program
        }

        // Ask if the user wants to continue
        cout << "\n\tDo you want to continue in the main menu (y/n): ";
        cin >> c;
    } while(c == 'y' || c == 'Y');

    return 0;
}


// Sample Input

// Source City: Mumbai
// Destination City: Delhi
// Distance: 1200

// Source City: Delhi
// Destination City: Kolkata
// Distance: 1500

// Source City: Mumbai
// Destination City: Chennai
// Distance: 1000

// Source City: Chennai
// Destination City: Kolkata
// Distance: 1600