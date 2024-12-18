/*
Aim: Imagine a publishing company which does marketing for book and audio cassette versions. 
Create a class publication that stores the title (a string) and price (type float) of publications. 
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. 
If an exception is caught, replace all the data member values with zero values.
*/

#include<iostream>
using namespace std;

class publication{
    
    private:
    string title;
    float price;

    public:

    publication(){
        title = "";
        price = 0.0;
    }

    void getdata(){

        cin.ignore();
        cout << "Enter the title of the book: ";
        getline(cin, title);
        // title = title1;

        cout << "Enter the price of the book: ";
        cin >> price;
        // price = price1;
    }


    void putdata(){
        cout << "Title: " << title << endl;
        cout << "Price: " << price << " Rs" << endl;
        cout << endl;
    }
};

class book : public publication{

    private:
    int pageCount;

    public:

    void getdata(){

        publication :: getdata();
        cout << "Enter the page count of the book: ";
        cin >> pageCount;
        // pageCount = pageCount1;

    }


    void putdata(){

        publication :: putdata();
        cout << "Page Count: " << pageCount << " pages" << endl;
        cout << endl;

    }

};

class tape : public publication{

    private:
    float playTime;

    public:

    void getdata(){

        publication :: getdata();
        cout << "Enter the play time of the book: ";
        cin >> playTime;

    }


    void putdata(){

        publication :: putdata();
        cout << "Play Time: " << playTime << " minutes" << endl;
        cout << endl;
    }

};

int main(){

    book book1;
    tape book2;

    cout << "Enter the details of the book: \n" << endl;
    book1.getdata();

    cout << "Book details: \n" << endl;
    book1.putdata();

    cout << "Enter the details of the book: \n" << endl;
    book2.getdata();

    cout << "Book details: \n" << endl;
    book2.putdata();

    return 0;
}