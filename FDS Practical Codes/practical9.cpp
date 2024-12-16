// Assignment No- 09

// Aim: To illustrate the concept of stack and string.

// Problem Statement: A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, ǁPoor Dan is in a droopǁ is a palindrome, as can be seen by examining the characters ―poor danisina droopǁ and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-
// in a palindrome, the sequence will be identical. Write C++ program with functions-
// 1. To check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome.
// 2. To remove spaces and punctuation in string, convert all the Characters to lowercase, and then call above Palindrome checking function to check for a palindrome
// 3. To print string in reverse order using stack

#include<iostream>
using namespace std;
#define MAX 100

class Stack{

    int arr[MAX];
    int top;

    public: 
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if(top == MAX-1){
                return true;
            }else{
                return false;
            }
        }

        void push(int value){
            if(isFull()){
                cout << "Stack overflow!"<<endl;
                return;
            }else{
                top++;
                arr[top] = value;
            }
        }

        char pop(){
            if(isEmpty()){
                cout<<"Stack underflow!"<<endl;
                return -1; 
            }
                char temp = arr[top];
                top--;
                return temp;
            
        }
};

string removeSpaces(string str){

    string result;

    // string str = "Taco cat";

    for(int i = 0;i < str.length(); i++){
        char ch = str[i];
        if(ch != ' '){
            result = result + ch;
        }
    }

    return result;
}

string removePunctuation(string str){

    string result;

    for(char i = 0;i < str.length(); i++){
        char ch = str[i];
        if( (ch>='A' && ch <= 'Z') || (ch>='a' && ch <= 'z') || (ch>='0' && ch <= '9') ){
            result+=ch;
        }
    }

    return result;
}

string convertToLowerCase(string str){

    // string str = "Tacocat";

    for (int i = 0; i < str.length(); i++){
        
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32 ;//('a' - 'A') 
        }
    }

    return str;
}

void palindromeCheck(string str){
    Stack s;

    for(int i = 0; i <str.length() ; i++){
        char ch = str[i];
        s.push(ch);
    }

    // string str = "t-a-c-o-c-a-t";

    for(int i = 0; i <str.length() ; i++){
        char ch = str[i];
        
        if(s.pop() != ch){
            cout << "The string is not palindrome" << endl;
            return;
        }
    }

    cout << "The string is palindrome" << endl;
}

void printReverse(string str){
    Stack s;

    for(int i = 0; i< str.length() ; i++){
        char ch = str[i];

        s.push(ch);
    }

    while(s.isEmpty() != true){
            cout << s.pop();
        }  
    

    cout << endl;
}

int main(){

    // string str = "Taco! cat@ %";
    // string str = "123";
    
    // string str = "Taco sdfcat";
    // string str = "Nitin";
    // string str = "abzzba";
    string str1 = "Madam, in Eden, I'm Adam.";

    // palindromeCheck(str1);

    str1 = removeSpaces(str1);
    str1 = removePunctuation(str1);
    str1 = convertToLowerCase(str1);

    // palindromeCheck(str1);
    // printReverse(str1);
    
    string str2 = "A nut for a jar of tuna!";
    printReverse(str2);
    printReverse(str1);

    // cout << str1;

    return 0;
}