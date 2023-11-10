#include <iostream>

using namespace std;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

typedef int (*ArithmeticFunction)(int, int);

int main() {
    ArithmeticFunction arithmeticFunctions[] = {add, subtract, multiply, divide};

    int choice;
    int num1, num2;

    do {
        cout << "Select an arithmetic operation:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;

            int result = arithmeticFunctions[choice - 1](num1, num2);

            cout << "Result: " << result << endl;
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Error: Division by zero.\n";
        return 0;
    }
}
