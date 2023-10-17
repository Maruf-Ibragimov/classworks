#include "../headers/common.h"

using namespace std;

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