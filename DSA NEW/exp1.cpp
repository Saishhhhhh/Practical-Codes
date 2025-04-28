// A1 Consider telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client's telephone number. Make use of two collision handling techniques
// and compare them using number of comparisons required to find a set of telephone numbers

#include <iostream>
using namespace std;


class node {
private:
    string name;
    string telephone;
    int key;

public:
    node() {
        key = 0;
        name = "";
    }
    friend class hashing; // To access the private members of class node
};

int ascii_generator(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum = sum + s[i];
    return sum % 100;
}


class hashing {
private:
    node data[100]; 
    string n;   
    string tele;     
    int k, index;     
    int size = 100;
    int collision_technique = 1; 
    int comparison_count = 0; 

public:
    hashing() {
        k = 0;
        comparison_count = 0;
    }

    // Function to reset comparison counter
    void reset_comparison_count() {
        comparison_count = 0;
    }

    // Function to get comparison count
    int get_comparison_count() {
        return comparison_count;
    }

    void set_collision_technique(int tech) {
        collision_technique = tech;
        if (tech == 1) {
            cout << "Collision handling technique set to Linear Probing" << endl;
        } else {
            cout << "Collision handling technique set to Quadratic Probing" << endl;
        }
    }

    // Function to create record
    void create_record(string n, string tele) {
        k = ascii_generator(n); // using ascii value of string as key
        index = k % size;
        
        if (collision_technique == 1) {
            // Linear Probing
            for (int j = 0; j < size; j++) {
                if (data[index].key == 0) {
                    data[index].key = k;
                    data[index].name = n;
                    data[index].telephone = tele;
                    break;
                }
                else{
                    index = (index + 1) % size;
                }
                    
            }
        } else {
            // Quadratic Probing
            for (int j = 0; j < size; j++) {
                int probe_index = (k + j * j) % size; // Calculate probe index based on original key
                if (data[probe_index].key == 0) {
                    data[probe_index].key = k;
                    data[probe_index].name = n;
                    data[probe_index].telephone = tele;
                    break;
                }
            }
        }
    }

    // Function to search for record based on name input
    void search_record(string name) {
        int flag = 0;
        int linear_comparisons = 0;
        int quadratic_comparisons = 0;
        string found_telephone;

        int key = ascii_generator(name);
        int start_index = key % size;

        // Linear Probing search
        for (int i = 0; i < size; i++) {
            int linear_index = (start_index + i) % size;
            linear_comparisons++;
            
            if (data[linear_index].key == key && data[linear_index].name == name) {
                flag = 1;
                found_telephone = data[linear_index].telephone;
                break;
            }
            
            // If we've checked an empty slot, we can stop searching
            if (data[linear_index].key == 0) {
                break;
            }
        }
        
        // Quadratic Probing search
        for (int i = 0; i < size; i++) {
            int quadratic_index = (start_index + i*i) % size;
            quadratic_comparisons++;
            
            if (data[quadratic_index].key == key && data[quadratic_index].name == name) {
                flag = 1;
                found_telephone = data[quadratic_index].telephone;
                break;
            }
            
            // If we've checked an empty slot, we can stop searching
            if (data[quadratic_index].key == 0) {
                break;
            }
        }
        
        // Display results
        cout << "\n--- Search Results for \"" << name << "\" ---" << endl;
        
        if (flag) {
            cout << "Record found!" << endl;
            cout << "Name: " << name << endl;
            cout << "Telephone: " << found_telephone << endl;
        } else {
            cout << "Record not found." << endl;
        }
        
        // Display performance comparison
        cout << "\n--- Performance Comparison ---" << endl;
        cout << "Linear Probing: " << linear_comparisons << " comparisons" << endl;
        cout << "Quadratic Probing: " << quadratic_comparisons << " comparisons" << endl;
        
        // Determine which method was more efficient
        if (linear_comparisons < quadratic_comparisons) {
            cout << "Linear Probing was more efficient by " 
                 << (quadratic_comparisons - linear_comparisons) << " comparisons." << endl;
        } else if (quadratic_comparisons < linear_comparisons) {
            cout << "Quadratic Probing was more efficient by " 
                 << (linear_comparisons - quadratic_comparisons) << " comparisons." << endl;
        } else {
            cout << "Both methods required the same number of comparisons." << endl;
        }
        
    }

    // Function to display the directory
    void display_record() {
        cout << "\t Name \t\t Telephone";
        for (int a = 0; a < size; a++) {
            if (data[a].key != 0) {
                cout << "\n\t" << data[a].name << " \t\t\t " << data[a].telephone;
            }
        }
    }
};

// Main Function
int main() {
    hashing s;
    string name;
    string telephone;
    int choice;
    bool loop = 1;

    // Menu driven code
    while (loop) {
        cout << "\n-------------------------" << endl
             << " Telephone book Database " << endl
             << "-------------------------" << endl
             << "1. Create Record" << endl
             << "2. Display Record" << endl
             << "3. Search Record" << endl
             << "4. Set Collision Technique" << endl
             << "5. Exit" << endl
             << "Enter choice :: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter name :: ";
            cin >> name;
            cout << "Enter Telephone number :: ";
            cin >> telephone;
            s.create_record(name, telephone);
        }
        else if (choice == 2) {
            s.display_record();
        }
        else if (choice == 3) {
            cout << "\nEnter the name :: ";
            cin >> name;
            s.search_record(name);
        }
        else if (choice == 4) {
            int tech;
            cout << "\nEnter collision technique (1 for Linear Probing, 2 for Quadratic Probing): ";
            cin >> tech;
            s.set_collision_technique(tech);
        }
        else if (choice == 5) {
            loop = 0;
        }
        else {
            cout << "\nYou Entered something wrong!";
        }
    }
    return 0;
}

// 1
// Enter name :: John
// Enter Telephone number :: 1234567890

// 1
// Enter name :: Alice
// Enter Telephone number :: 9876543210

// 1
// Enter name :: Bob
// Enter Telephone number :: 5555555555

// 2
// Name            Telephone
// John            1234567890
// Alice           9876543210
// Bob             5555555555

// 3
// Enter the name :: Alice
// Record found
// Name :: Alice
// Telephone :: 9876543210

// preet, arjun = 44
// preeti, priya = 49
// Tanvi, Atharv, Kartik = 14
// Hash 99: Nisha, Mohan, Abhishek
// Arjun, Arvind, Vinod, Shubham = 12