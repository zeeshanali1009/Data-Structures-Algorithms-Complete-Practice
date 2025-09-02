#include <iostream>
#include <string>
using namespace std;

// Helper function to check if character is alphanumeric
bool isAlphaNumeric(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

// Helper function to convert a character to lowercase
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A'); // Convert to lowercase
    }
    return ch;
}

// Main palindrome check function
bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Move left to next alphanumeric
        while (left < right && !isAlphaNumeric(s[left])) {
            left++;
        }

        // Move right to previous alphanumeric
        while (left < right && !isAlphaNumeric(s[right])) {
            right--;
        }

        // Compare after converting to lowercase
        if (toLower(s[left]) != toLower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The string is a valid palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
