#include <iostream>

using namespace std;

int* findMiddle(int* arr, int size) {
    if (size == 0 || size % 2 == 0) {
        return nullptr;
    }

    int middleIndex = size / 2;
    int* middlePointer = arr + middleIndex;
    return middlePointer;
}

int main() {
    int arr[] = {1, 5, 765, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* middleElement = findMiddle(arr, size);

    cout << "The middle element is: " << *middleElement << endl;


    return 0;
}
