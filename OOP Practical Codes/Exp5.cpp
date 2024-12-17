// Aim: Write a function template for selection sort that inputs, sorts, 
// and outputs an integer array and a float array.

#include <iostream>
using namespace std;

int n;
#define size 10

template<class T>
void sel(T A[size]) {
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
}

int main() {
    int choice;
    int A[size];
    float B[size];
    int i;
    do {
        cout << "\n 1. Integer : ";
        cout << "\n 2. Float : ";
        cout << "\n 3. Exit : " << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "\nEnter Total Number Of Integer Elements:";
                cin >> n;
                cout << "\nEnter Integer Elements:";
                for (i = 0; i < n; i++) {
                    cin >> A[i];
                }
                sel(A);
                break;
            }
            case 2: {
                cout << "\nEnter Total Number Of Float Elements:";
                cin >> n;
                cout << "\nEnter Float Elements:";
                for (i = 0; i < n; i++) {
                    cin >> B[i];
                }
                sel(B);
                break;
            }
            case 3: {
                cout << "**********Program Exited Successfully**********" << endl;
                exit(0);
            }
            default: {
                cout << "\n Invalid";
            }
        }
    } while (choice != 4);
    return 0;
}


/* Example Input:
1. Integer:
Enter Total Number Of Integer Elements: 5
Enter Integer Elements: 5 3 8 1 4

2. Float:
Enter Total Number Of Float Elements: 3
Enter Float Elements: 2.5 1.2 3.8
*/
