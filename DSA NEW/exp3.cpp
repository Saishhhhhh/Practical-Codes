// Problem Statement:
// C++ Program to read details of a book consists of chapters, chapters consist of sections and sections consist of
// subsections. Construct a tree and print the nodes. Find the time and space requirements of your
// method.

#include<iostream>
#include<string>
using namespace std;

struct BookNode{
    string title;
    int childCount;
    BookNode *children[10];
};

BookNode *bookRoot = NULL;

BookNode *createNewNode(string nodeTitle){
    BookNode *newNode = new BookNode;

    newNode->title = nodeTitle;
    newNode->childCount = 0;

    for(int i = 0; i < 10; i++){
        newNode->children[i] = NULL;
    }

    return newNode;
}

void createBookStructure(){
    string bookTitle, chapterTitle, sectionTitle, subSectionTitle;
    int chapterCount, sectionCount, subSectionCount;

    cout << "Enter the name of the book: ";
    cin >> bookTitle;

    bookRoot = createNewNode(bookTitle);

    cout << "Enter the number of chapters: ";
    cin >> chapterCount;

    bookRoot->childCount = chapterCount;

    for(int i = 0; i < chapterCount; i++){
        cout << "Enter the name of chapter " << i+1 << " : ";
        cin >> chapterTitle;

        bookRoot->children[i] = createNewNode(chapterTitle);

        cout << "Enter the number of sections in chapter " << i+1 << " : ";
        cin >> sectionCount;

        bookRoot->children[i]->childCount = sectionCount;

        for(int j = 0; j < sectionCount; j++){
            cout << "Enter the name of section " << j+1 << " : ";
            cin >> sectionTitle;

            bookRoot->children[i]->children[j] = createNewNode(sectionTitle);

            cout << "Enter the number of sub sections in section " << j+1<< " : ";
            cin >> subSectionCount;

            bookRoot->children[i]->children[j]->childCount = subSectionCount;

            for(int k = 0; k < subSectionCount; k++){
                cout << "Enter the name of the sub section " << k+1 << " : ";
                cin >> subSectionTitle;

                bookRoot->children[i]->children[j]->children[k] = createNewNode(subSectionTitle);
            }
        }
    }

    cout << "Book structure created successfully !" << endl;
}

void displayBookStructure(){
    if(bookRoot == NULL){
        cout << "No book has been created yet. Please create a book first..." << endl;
        return ;
    }

    cout << "Book Structure" << endl;

    cout << "Book: " << bookRoot->title << endl;

    for (int i = 0; i < bookRoot->childCount; i++){
        cout << "   Chapter " << i+1 << ": " << bookRoot->children[i]->title << endl;;
            for (int j = 0; j < bookRoot->children[i]->childCount; j++){
                cout << "       Section " << j+1 << ": " << bookRoot->children[i]->children[j]->title << endl;;
                    for (int k = 0; k < bookRoot->children[i]->children[j]->childCount; k++){
                        cout << "           Sub Section " << k+1 << ": " << bookRoot->children[i]->children[j]->children[k]->title << endl;;
                    }
            }
    }
}

int main(){

    int choice;

    while(true){
        cout << "\n-----------------------" << endl;
        cout << "Book Structure Manager" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Create Book Structure" << endl;
        cout << "2. Display Book Hierarchy" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if(choice == 1){
            createBookStructure();
        }else if(choice == 2){
            displayBookStructure();
        }else if(choice == 3){
            cout << "Thank you for using the Book Structure Manager!" << endl;
            break;
        }else{
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}