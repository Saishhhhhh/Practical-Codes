/*
Aim: Imagine a publishing company which does marketing for book and audio cassette versions. 
Create a class publication that stores the title (a string) and price (type float) of publications. 
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. 
If an exception is caught, replace all the data member values with zero values.
*/
#include <iostream>
#include <string>
using namespace std;

class publication {

private:
    string title;
    float price;

public:
    publication() {
        title = "";
        price = 0.0;
    }

    void getdata() {
        cin.ignore();
        cout << "Enter the title of the publication: ";
        getline(cin, title);

        cout << "Enter the price of the publication: ";
        cin >> price;

        if (cin.fail() || price < 0) {
            throw "Invalid price entered! Price must be a non-negative number.";
        }
    }

    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << " Rs" << endl;
    }

    void reset() {
        title = "";
        price = 0.0;
    }
};

class book : public publication {

private:
    int pageCount;

public:
    book(){
        pageCount = 0;
    }

    void getdata() {
        publication::getdata();

        cout << "Enter the page count of the book: ";
        cin >> pageCount;

        if (cin.fail() || pageCount < 0) {
            throw "Invalid page count entered! Page count must be a non-negative integer.";
        }
    }

    void putdata() {
        publication::putdata();
        cout << "Page Count: " << pageCount << " pages" << endl;
    }

    void reset() {
        publication::reset();
        pageCount = 0;
    }
};

class tape : public publication {

private:
    float playTime;

public:
    tape(){
        playTime = 0.0;
    }

    void getdata() {
        publication::getdata();

        cout << "Enter the play time of the tape: ";
        cin >> playTime;

        if (cin.fail() || playTime < 0) {
            throw "Invalid play time entered! Play time must be a non-negative number.";
        }
    }

    void putdata() {
        publication::putdata();
        cout << "Play Time: " << playTime << " minutes" << endl;
    }

    void reset() {
        publication::reset();
        playTime = 0.0;
    }
};

int main() {

    book book1;
    tape tape1;

    try {
        cout << "Enter the details of the book:\n" << endl;
        book1.getdata();
    } catch (const char *msg) {
        cout << "Error: " << msg << endl;
        book1.reset();
    }

    cout << "\nBook details:\n" << endl;
    book1.putdata();

    try {
        cout << "Enter the details of the tape:\n" << endl;
        tape1.getdata();
    } catch (const char *msg) {
        cout << "Error: " << msg << endl;
        tape1.reset();
    }

    cout << "\nTape details:\n" << endl;
    tape1.putdata();

    return 0;
}
