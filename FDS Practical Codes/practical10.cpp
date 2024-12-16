// Assignment No- 10

// Aim: To illustrate the various concept of stack.

// Problem Statement: In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not.

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
                return ;
            }else{
                top++;
                arr[top]=value;
            }
        }

        char pop(){
            if(isEmpty()){
                cout << "Stack underflow!" <<endl;
                return -1;
            }

            char temp = arr[top];
            top--;
            return temp;
        }
};

bool expressionCheck(string str){
    Stack s;

    //"[(a+b)*(c-d)]"

    for(int i = 0; i<str.length(); i++){

        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(s.isEmpty() == true){
                return false;
            }

            char top = s.pop();  //top = "["
            if(ch == ')' ){
                if( top != '(' ){
                    return false;
                }
            }
            if(ch == '}'){
                if(top != '{'){
                    return false; 
                }
            }
            if(ch == ']'){
                if(top != '['){
                    return false;
                }
            }
        }
    }

    if(s.isEmpty() == true){
        return true;
    }else{
        return false;
    }
}

int main(){

    string str = "[(a+b)*(c-d)]";

    if (expressionCheck(str) == true) {
        cout << "The expression is well parenthesized." << endl;
    } else {
        cout << "The expression is NOT well parenthesized." << endl;
    }

    return 0;
}