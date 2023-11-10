#include <iostream>

using namespace std;

int main(){

    int *numberArray = new int[5];

    for(int i = 0; i < 5; ++i){
        numberArray[i] = i * i;
    }

    for(int i = 0; i < 5; ++i){
        cout << "Number Array[" << i << "] = " << numberArray[i] << "\n";
    }

    delete[]numberArray;
    numberArray = nullptr;
    
    cout << "Program Completed." << "\n";

    return 0;
}