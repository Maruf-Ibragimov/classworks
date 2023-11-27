// #include <iostream>
// #include <cstring>

// using namespace std;

// class String {
// private:
//     char *str;

// public:
//     String() : str(nullptr) {}
//     String(char *s) {
//         if (s != nullptr) {
//             str = new char[strlen(s) + 1];
//             strcpy(str, s);
//         } else {
//             str = nullptr;
//         }
//         delete[] str;
//     }
// 
//    void display() {
//        if (str != nullptr) {
//            for (size_t i = 0; i < strlen(str); ++i) {
//                cout << str[i];
//            }
//            cout << endl;
//        } else {
//            cout << "String is empty." << endl;
//        }
//    }
// };
// 
// int main() {
//     String str1;
//     String str2("Hello, World!"); 

//     cout << "String 1: ";
//     str1.display(); 

//     cout << "String 2: ";
//     str2.display();

//     return 0;
// }


#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    ~String() {
        delete[] str;
    }

    void display() const {
        if (str != nullptr) {
           for (size_t i = 0; i < strlen(str); ++i) {
               cout << str[i];
           }
           cout << endl;
       } else {
           cout << "String is empty." << endl;
       }
    }
};


int main() {
    String str1;
    String str2("Hello, World!"); 

    str1.display(); 
    str2.display();

    return 0;
}
