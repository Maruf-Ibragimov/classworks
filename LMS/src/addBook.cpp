#include "../headers/common.h"

using namespace std;

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