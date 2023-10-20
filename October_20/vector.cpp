#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> reverseVector(const std::vector<int> &v) {
    std::vector<int> reversed;

    for (int i = v.size() - 1; i >= 0; --i) {
        reversed.push_back(v[i]);
    }

    return reversed;
}

void removeOdd(std::vector<int> &v) {
    v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return n % 2 != 0; }), v.end());
}

bool isPalindrome(const std::vector<int> &v) {
    int left = 0;
    int right = v.size() - 1;

    while (left < right) {
        if (v[left] != v[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    // Here is the reverseVector() function
    std::vector<int> original = {1, 2, 3, 4, 5};
    std::vector<int> reversed = reverseVector(original);

    std::cout << "\nOriginal Vector: ";
    for (int num : original) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Reversed Vector: ";
    for (int num : reversed) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    // Here is I am using removeOdd() function
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    removeOdd(numbers);

    std::cout << "\nAfter removing odd numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    // Here I am using isPalindrome() function
    std::vector<int> palindrome = {1, 2, 3, 2, 1};
    std::vector<int> notPalindrome = {1, 2, 3, 4, 5};

    std::cout << "\nIs 'palindrome' a palindrome? " << (isPalindrome(palindrome) ? "Yes" : "No") << std::endl;
    std::cout << "Is 'notPalindrome' a palindrome? " << (isPalindrome(notPalindrome) ? "Yes" : "No\n") << std::endl;

    return 0;
}