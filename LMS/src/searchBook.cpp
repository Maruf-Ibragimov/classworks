#include "../headers/common.h"

using namespace std;

void searchBook() {
    string searchTerm;
    cout << "\nEnter title | author | ISBN to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    for (const auto &book : books) {
        if (book.title == searchTerm || book.author == searchTerm || book.isbn == searchTerm) {
            cout << "\nFound: " << book.title << "| " << book.author << "| " << book.isbn << "| " << book.year << "\n";
        }
    }
}