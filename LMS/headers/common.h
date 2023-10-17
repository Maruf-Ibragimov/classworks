
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structure to represent a book
struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    int year;
};

// Global vector to store the books
extern std::vector<Book> books;

// Function prototypes
void addBook();
void removeBook();
void searchBook();
void listBooks();

#endif // COMMON_H