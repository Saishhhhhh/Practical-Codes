/*
Aim: To illustrate the concept of stack and string.

Problem Statement: A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, 
and spaces are ignored. For example, ǁPoor Dan is in a droopǁ is a palindrome, as can be seen by examining 
the characters ―poor danisina droopǁ and observing that they are the same forward and backward. 
One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-
in a palindrome, the sequence will be identical. Write C++ program with functions-

1. To check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome.
2. To remove spaces and punctuation in string, convert all the Characters to lowercase, and then call above Palindrome checking function to check 
    for a palindrome
3. To print string in reverse order using stack
*/

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    for (char ch : str) {
        if (ch != s.top()) {
            return false;
        }
        s.pop();
    }
    return true;
}

bool checkPalindromeWithPreprocessing(const string& str) {
    string cleanedStr = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            cleanedStr += tolower(ch);
        }
    }
    return isPalindrome(cleanedStr);
}

void printReverseUsingStack(const string& str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    cout << "Reversed String: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    cout << "\nChecking if the string is a palindrome...\n";
    if (checkPalindromeWithPreprocessing(input)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is not a palindrome.\n";
    }

    cout << "\nPrinting the string in reverse order:\n";
    printReverseUsingStack(input);

    return 0;
}
