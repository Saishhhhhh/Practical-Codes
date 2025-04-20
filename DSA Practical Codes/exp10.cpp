// Read the marks obtained by students of second year in an online examination of particular subject. 
// Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyse the algorithm.

#include <iostream>
using namespace std;

const int MAX = 20;

class Stud {
    int mks[MAX];

public:
    Stud() {
        for (int i = 0; i < MAX; i++)
            mks[i] = 0;
    }

    void insertHeap(int tot);
    void displayHeap(int tot);
    void showMax(int tot);
    void showMin();
};

void Stud::insertHeap(int tot) {
    for (int i = 1; i <= tot; i++) {
        cout << "Enter marks: ";
        cin >> mks[i];

        int j = i;
        int par = j / 2;

        while (j > 1 && mks[j] < mks[par]) {  // Min Heap condition
            int tmp = mks[j];
            mks[j] = mks[par];
            mks[par] = tmp;
            j = par;
            par = j / 2;
        }
    }
}

void Stud::displayHeap(int tot) {
    int i = 1, space = 6;
    cout << "\nMin Heap Display:\n";
    while (i <= tot) {
        if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16) {
            cout << "\n\n";
            for (int j = 0; j < space; j++)
                cout << " ";
            space -= 2;
        }
        cout << mks[i] << " ";
        i++;
    }
    cout << endl;
}

void Stud::showMax(int tot) {
    int max1 = mks[1];
    for (int i = 2; i <= tot; i++) {
        if (max1 < mks[i])
            max1 = mks[i];
    }
    cout << "\nMax Marks: " << max1;
}

void Stud::showMin() {
    cout << "\nMin Marks (Root of Min Heap): " << mks[1];
}

int main() {
    cout << "Name: Anjali Shirke\tBatch: B1\tRoll no. 23207\n";

    int ch, cont, total = 0;
    Stud s1;

    do {
        cout << "\n======= MENU =======";
        cout << "\n1. Read marks of the student";
        cout << "\n2. Display Min Heap";
        cout << "\n3. Find Max Marks";
        cout << "\n4. Find Min Marks";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "How many students? ";
            cin >> total;
            if (total >= MAX) {
                cout << "Limit exceeded! Max " << MAX - 1 << " students allowed.\n";
                total = MAX - 1;
            }
            s1.insertHeap(total);
            break;

        case 2:
            if (total > 0)
                s1.displayHeap(total);
            else
                cout << "No data available. Please insert marks first.";
            break;

        case 3:
            if (total > 0)
                s1.showMax(total);
            else
                cout << "No data available.";
            break;

        case 4:
            if (total > 0)
                s1.showMin();
            else
                cout << "No data available.";
            break;

        default:
            cout << "Invalid choice. Please try again.";
        }

        cout << "\nDo you want to continue? (1 for Yes / 0 for No): ";
        cin >> cont;
    } while (cont == 1);

    return 0;
}

// First, run the program and select option 1 to read marks:
// How many students? 5
// Enter marks: 85
// Enter marks: 92
// Enter marks: 78
// Enter marks: 95
// Enter marks: 88

// Then select option 2 to display the Min Heap structure
// Min Heap Display:

//       78
//   85      88
// 92  95

// Select option 3 to find the maximum marks
// Max Marks: 95

// Select option 4 to find the minimum marks:
// Min Marks (Root of Min Heap): 78


// When asked "Do you want to continue? (1 for Yes / 0 for No):", enter 1 to try more operations or 0 to exit.