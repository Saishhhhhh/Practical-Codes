// Problem Statement :
// There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
// The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent 
// this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or 
// use adjacency matrix representation of the graph. Justify the storage representation used.


#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Constants for better readability
#define MAX_CITIES 10

class FlightGraph {
private:
    int distanceMatrix[MAX_CITIES][MAX_CITIES];  // Stores distances between cities
    vector<string> cityNames;  // Stores names of cities using vector of strings
    int totalCities;  // Total number of cities in the graph

public:
    // Constructor to initialize the graph
    FlightGraph() {
        totalCities = 0;
        // Initialize all distances as 0
        for(int i = 0; i < MAX_CITIES; i++) {
            for(int j = 0; j < MAX_CITIES; j++) {
                distanceMatrix[i][j] = 0;
            }
        }
    }

    // Function to add a new city to the graph
    int addCity(const string& cityName) {
        // Check if city already exists
        for(int i = 0; i < totalCities; i++) {
            if(cityNames[i] == cityName) {
                return i;  // Return existing city index
            }
        }
        // Add new city if not exists
        if(totalCities < MAX_CITIES) {
            cityNames.push_back(cityName);
            return totalCities++;
        }
        return -1;  // Return -1 if maximum cities reached
    }

    // Function to create the flight graph
    void createGraph() {
        string sourceCity;
        string destCity;
        int distance;
        char choice;

        do {
            cout << "\nEnter Source City: ";
            cin >> sourceCity;
            cout << "Enter Destination City: ";
            cin >> destCity;

            // Add cities to graph if they don't exist
            int sourceIndex = addCity(sourceCity);
            int destIndex = addCity(destCity);

            if(sourceIndex == -1 || destIndex == -1) {
                cout << "Maximum number of cities reached!" << endl;
                return;
            }

            cout << "Enter Distance (in km) between " << sourceCity << " and " << destCity << ": ";
            cin >> distance;

            // Store distance in both directions (undirected graph)
            distanceMatrix[sourceIndex][destIndex] = distance;
            distanceMatrix[destIndex][sourceIndex] = distance;

            cout << "\nDo you want to add more connections? (y/n): ";
            cin >> choice;
        } while(choice == 'y' || choice == 'Y');
    }

    // Function to display the flight graph
    void displayGraph() {
        if(totalCities == 0) {
            cout << "\nNo cities added to the graph yet!" << endl;
            return;
        }

        cout << "\nFlight Distance Matrix (in km):" << endl;
        cout << "--------------------------------" << endl;

        // Print header with city names
        cout << "\t";
        for(int i = 0; i < totalCities; i++) {
            cout << cityNames[i] << "\t";
        }
        cout << endl;

        // Print distance matrix
        for(int i = 0; i < totalCities; i++) {
            cout << cityNames[i] << "\t";
            for(int j = 0; j < totalCities; j++) {
                cout << distanceMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "========== FLIGHT ROUTE GRAPH ==========" << endl;
    cout << "This program creates a graph of flight routes between cities" << endl;
    cout << "and displays the distance matrix between them." << endl;

    FlightGraph flightGraph;
    int choice;
    char continueChoice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add flight routes" << endl;
        cout << "2. Display distance matrix" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                flightGraph.createGraph();
                break;
            case 2:
                flightGraph.displayGraph();
                break;
            case 3:
                cout << "Thank you for using the program!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> continueChoice;
    } while(continueChoice == 'y' || continueChoice == 'Y');

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