#include "../headers/common.h"

using namespace std;

void removeBook() {
    string isbn;
    cout << "\nEnter ISBN of book to remove: ";
    cin >> isbn;

    // Search and remove (Using vector's erase-remove idiom)
    books.erase(remove_if(books.begin(), books.end(),
                               [&isbn](const Book &b) { return b.isbn == isbn; }),
                books.end());

    cout << "Book removed successfully (if it was present).\n";
}