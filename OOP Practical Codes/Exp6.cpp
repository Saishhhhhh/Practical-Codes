// Aim: Write a C++ program using STL for sorting and searching user-defined 
// records such as Item records (Item code, name, cost, quantity, etc.) 
// using vector container.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class items{
    public:

    int code;
    string name;
    float cost;
    int quantity;

    items(){
        code = 0;
        name = "";
        cost = 0;
        quantity = 0;
    }

    void getData(){
        cout << "Enter code: ";
        cin >> code;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter cost: ";
        cin >> cost;
        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void display(){
        cout << "Code: " << code
             << ", Name: " << name
             << ", Cost: " << cost
             << ", Quantity: " << quantity << endl;
    }
};

void displayItems(vector<items> v1){
    for(vector<items> :: iterator lol = v1.begin(); lol != v1.end(); lol++){
        lol->display();
    }
}

bool compareByCode(items &obj1, items &obj2){
    return obj1.code < obj2.code;
}

bool compareByCost(items &obj1, items &obj2){
    return obj1.cost < obj2.cost;
}

void sortItemsByCode(vector<items> & obj){
    sort(obj.begin(), obj.end(),compareByCode);
}

void sortItemsByCost(vector<items> & obj){
    sort(obj.begin(), obj.end(),compareByCost);
}

items *search(vector<items> &v1, int code){
    for(vector<items> :: iterator lol = v1.begin(); lol != v1.end() ; lol++){
        if(lol->code == code ){
            return &(*lol);
        }
    }
    return nullptr;
}


int main(){

    vector<items> v; 
    int n;

    cout << "Enter the number of items to store: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for item " << i + 1 << ":\n";
        items item;
        item.getData();
        v.push_back(item);
    }

    cout << "Items entered: " << endl;
    displayItems(v);

    int searchCode;
    cout << "\nEnter the code of the item to search for: ";
    cin >> searchCode;


    items* foundItem = search(v, searchCode);

    if (foundItem) {
        cout << "\nItem found:\n";
        foundItem->display();
    } else {
        cout << "\nItem with code " << searchCode << " not found.\n";
    }

    int choice;
    cout << "\nChoose sorting option:\n1. Sort by Code\n2. Sort by Cost\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        sortItemsByCode(v); // Sort by code
        cout << "\nItems sorted by Code:\n";
        displayItems(v);
    } else if (choice == 2) {
        sortItemsByCost(v); // Sort by cost
        cout << "\nItems sorted by Cost:\n";
        displayItems(v);
    } else {
        cout << "\nInvalid choice. No sorting performed.\n";
    }

    return 0;
}
