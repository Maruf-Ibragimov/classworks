#include "../headers/common.h"

using namespace std;

void listBooks() {
    cout << "\nList of Books:\n";
    for (const auto &book : books) {
        cout << book.title << "| " << book.author << "| " << book.isbn << "| " << book.year << "\n";
    }
}