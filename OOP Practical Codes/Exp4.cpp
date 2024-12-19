// Aim: Write a C++ program that creates an output file, writes information to it, 
// closes the file and opens it again as an input file and reads the information from the file.

#include<iostream>
#include<fstream>
using namespace std;

int main(){

    fstream file;

    long long int phone;
    long long int phoneRead;

    file.open("telephone.txt", ios :: out);

    if(!file){
        cout << "File could no be opened.";
        return 1;
    }

    cout << "Enter your phone no: ";
    cin >> phone;

    file << phone << endl;

    file.close();

    file.open("telephone.txt" , ios :: in);

    if(!file){
        cout << "File could not be opened.";
        return 1;
    }

    while(file >> phoneRead){
        cout << phoneRead << endl;
    }

    file.close();

    return 0;
}