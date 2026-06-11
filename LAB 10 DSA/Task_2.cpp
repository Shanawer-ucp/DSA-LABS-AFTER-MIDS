// Task 2 - Recursive Palindrome Check
// DSA Lab 10 - Recursion

#include <iostream>
#include <string>
using namespace std;

// Base case: if left index >= right index, all chars matched -> palindrome
// Recursive case: compare outermost chars, move inward
bool isPalindrome(const string& str, int left, int right) {
    if (left >= right)
        return true;

    if (str[left] != str[right])
        return false;

    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string words[] = {"racecar", "hello", "madam", "world", "level"};
    int count = 5;

    for (int i = 0; i < count; i++) {
        string word = words[i];
        bool result = isPalindrome(word, 0, word.length() - 1);
        cout << "\"" << word << "\" -> "
             << (result ? "Palindrome" : "Not a Palindrome") << endl;
    }

    return 0;
}
