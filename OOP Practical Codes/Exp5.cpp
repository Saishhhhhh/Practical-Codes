// Aim: Write a function template for selection sort that inputs, sorts, 
// and outputs an integer array and a float array.

// Write a function template selectionSort. Write a program that inputs, sorts and outputs an int array and a float array.

#include<iostream>
using namespace std;

template <typename T>
T selectionSort(T arr[], int size){
    
    for(int i = 0; i < size-1; i++){
        int minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

}

int main(){

    int intArr[] = {64, 25, 12, 22, 11};
    int n = 5;

    cout<<"Unsorted Array: ";
    for(int i = 0; i < n ; i++){
        cout << intArr[i] << " ";
    }
    cout << endl;

    selectionSort(intArr, n);

    cout<<"Sorted Array: ";
    for(int i = 0; i < n ; i++){
        cout << intArr[i] << " ";
    }
    cout << endl;

    float floatArr[] = {64.5, 25.1, 12.3, 22.7, 11.8};
    int m = 5;

    cout<<"Unsorted Array: ";
    for(int i = 0; i < m ; i++){
        cout << floatArr[i] << " ";
    }
    cout << endl;

    selectionSort(floatArr, m);

    cout<<"Sorted Array: ";
    for(int i = 0; i < m ; i++){
        cout << floatArr[i] << " ";
    }
    cout << endl;

    return 0;
}