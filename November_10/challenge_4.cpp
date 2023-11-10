#include <iostream>

using namespace std;

void minmax(int *arr, int size, int *min, int *max) {
    if (size == 0) {
        cerr << "Error: Empty array\n";
        return;
    }

    *min = *max = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < *min) {
            *min = arr[i];
        } else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    const int size = 6;
    int myArray[size] = {3, 8, 1, 6, 2, 7};

    int minValue, maxValue;

    minmax(myArray, size, &minValue, &maxValue);

    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }

    cout << "\nMinimum value: " << minValue << "\n";
    cout << "Maximum value: " << maxValue << "\n";

    return 0;
}
