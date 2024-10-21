/*
Aim: To illustrate the various concept of stack.

Problem Statement: In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
Write C++ program using stack to check whether given expression is well parenthesized or not.

*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isWellParenthesized(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "The expression is well parenthesized.\n";
    } else {
        cout << "The expression is not well parenthesized.\n";
    }

    return 0;
}

/*
    INPUT  

    Enter a string: Poor Dan is in a droop
 
*/
