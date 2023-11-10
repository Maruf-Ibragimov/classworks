#include <iostream>

using namespace std;

void myStrcpy(char *destination, const char *source) {
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    *destination = '\0';
}

int main() {
    const char *sourceString = "Hello, World!";
    char destinationString[50];

    myStrcpy(destinationString, sourceString);

    cout << "Source String: " << sourceString << endl;
    cout << "Copied String: " << destinationString << endl;

    return 0;
}
