#include <iostream>

using namespace std;

int strLength(const char *str) {
    const char *ptr = str;

    while (*ptr != '\0') {
        ptr++;
    }

    return static_cast<int>(ptr - str);
}

int main() {
    const char *myString = "Hello, World!";

    cout << "Length of the string: " << strLength(myString) << endl;

    return 0;
}
