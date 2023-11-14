#include <iostream>

using namespace std;

int* duplicateArray(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return nullptr;
    }

    int* duplicate = new int[size];
    for (int i = 0; i < size; ++i) {
        duplicate[i] = arr[i];
    }
    return duplicate;
}

int main() {
    int originalArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(originalArray) / sizeof(originalArray[0]);

    int* duplicatedArray = duplicateArray(originalArray, size);


    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << originalArray[i] << " ";
    }
    cout << endl;


    cout << "Duplicated Array: ";
    for (int i = 0; i < size; ++i) {
        cout << duplicatedArray[i] << " ";
    }
    cout << endl;

    delete[] duplicatedArray;

    return 0;
}
