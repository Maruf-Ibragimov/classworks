#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    int year;
};

void addBook();
void removeBook();
void searchBook();
void listBooks();

vector<Book> books;

int main() {
    int choice;

    do {
        cout << "\n=====Welcome to Our Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. List Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                addBook(); 
                break;
            }
            case 2: {
                removeBook(); 
                break;
            }
            case 3: {
                searchBook(); 
                break;
            }
            case 4: {
                listBooks(); 
                break;
            }
            case 5: {
                cout << "Goodbye!\n"; 
                break;
            }
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 5);

    return 0;
}

void addBook() {
    Book newBook;

    cout << "\nEnter book title: ";
    cin.ignore();
    getline(cin, newBook.title);

    cout << "Enter author: ";
    getline(cin, newBook.author);

    cout << "Enter ISBN: ";
    cin >> newBook.isbn;

    cout << "Enter publication year: ";
    cin >> newBook.year;

    books.push_back(newBook);

    cout << "Book added successfully!\n";
}

void removeBook() {
    string isbn;
    cout << "\nEnter ISBN of book to remove: ";
    cin >> isbn;

    books.erase(remove_if(books.begin(), books.end(),
                               [&isbn](const Book &b) { return b.isbn == isbn; }),
                books.end());

    cout << "Book removed successfully (if it was present).\n";
}

void searchBook() {
    string searchTerm;
    cout << "\nEnter title | author | ISBN to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    for (const auto &book : books) {
        if (book.title == searchTerm || book.author == searchTerm || book.isbn == searchTerm) {
            cout << "\nFound: " << book.title << " | " << book.author << " | " << book.isbn << " | " << book.year << "\n";
        }
    }
}

void listBooks() {
    cout << "\nList of Books:\n";
    for (const auto &book : books) {
        cout << book.title << " | " << book.author << " | " << book.isbn << " | " << book.year << "\n";
    }
}