#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 5, y = 10;
    
    swap(&x, &y);

    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
