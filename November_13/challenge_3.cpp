#include <iostream>

using namespace std;

int countChar(const char* str, char c) {
    int count = 0;

    while (*str != '\0') {
        if (*str == c) {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    const char* myString = "Hello, world!";
    char targetChar = 'l';

    int result = countChar(myString, targetChar);

    cout << "The character '" << targetChar << "' appears " << result << " times in the string." << endl;

    return 0;
}
