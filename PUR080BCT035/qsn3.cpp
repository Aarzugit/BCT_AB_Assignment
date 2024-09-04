/*
Define a class Library with bookTitle, author, and numberOfCopies as data
members. Implement methods to add new books, issue books, and return books.
Ensure that the number of copies is appropriately updated for each operation.
*/
#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    static const int MAX_BOOKS = 100; 
    string bookTitles[MAX_BOOKS];
    string authors[MAX_BOOKS];
    int numberOfCopies[MAX_BOOKS];
    int bookCount; 

public:
    Library() : bookCount(0) {}

    void addBook(const string& title, const string& author, int numCopies) {
        if (numCopies < 0) {
            cout << "Number of copies cannot be negative." << endl;
            return;
        }
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full, cannot add more books." << endl;
            return;
        }
        bookTitles[bookCount] = title;
        authors[bookCount] = author;
        numberOfCopies[bookCount] = numCopies;
        bookCount++;
        cout << "Book added successfully." << endl;
    }

    void issueBook(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (bookTitles[i] == title) {
                if (numberOfCopies[i] > 0) {
                    numberOfCopies[i]--;
                    cout << "Book issued successfully." << endl;
                } else {
                    cout << "No copies available." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void returnBook(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (bookTitles[i] == title) {
                numberOfCopies[i]++;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void displayBooks() const {
        for (int i = 0; i < bookCount; i++) {
            cout << "Title: " << bookTitles[i] << ", Author: " << authors[i] << ", Copies: " << numberOfCopies[i] << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string title, author;
        int numCopies;

        switch (choice) {
            case 1:
                cout << "Enter the title of the book: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter the author of the book: ";
                getline(cin, author);
                cout << "Enter the number of copies: ";
                cin >> numCopies;
                lib.addBook(title, author, numCopies);
                break;

            case 2:
                cout << "Enter the title of the book to issue: ";
                cin.ignore();
                getline(cin, title);
                lib.issueBook(title);
                break;

            case 3:
                cout << "Enter the title of the book to return: ";
                cin.ignore();
                getline(cin, title);
                lib.returnBook(title);
                break;

            case 4:
                lib.displayBooks();
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
