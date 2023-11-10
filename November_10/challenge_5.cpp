#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const char *firstString = "Hello, ";
    const char *secondString = "World!";

    char *concatenatedString = new char[strlen(firstString) + strlen(secondString) + 1];

    if (!concatenatedString) {
        cerr << "Memory allocation failed\n";
        return 1;
    }

    strcpy(concatenatedString, firstString);
    strcat(concatenatedString, secondString);

    cout << "Concatenated String: " << concatenatedString << endl;

    delete[] concatenatedString;

    return 0;
}
