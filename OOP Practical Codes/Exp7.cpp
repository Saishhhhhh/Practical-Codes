// Aim: Write a program in C++ to use map associative container. 
// The keys will be the names of states and the values will be the populations of the states. 
// When the program runs, the user is prompted to type the name of a state. 
// The program then looks in the map, using the state name as an index and returns the population of the state.

#include<iostream>
#include<map>
using namespace std;

int main(){
    string state;

    map<string, int> mpp;
    mpp.emplace("Maharashtra", 800);
    mpp.emplace("Tamil Nadu", 700);
    mpp.emplace("Goa", 200);
    mpp.emplace("Gujarat", 700);
    mpp.emplace("Rajasthan", 600);
    mpp.emplace("Bihar", 900);
    mpp.emplace("Uttar Pradesh", 1000);
    mpp.emplace("Punjab", 500);
    mpp.emplace("Assam", 400);
    mpp.emplace("Jammu Kashmir", 400);

    
    cout << "Enter the name of the state: ";
    cin >> state;

    map<string, int> :: iterator lol = mpp.find(state);
    cout << "Population of " << (*lol).first << " is " << (*lol).second << endl; 

    return 0;
}