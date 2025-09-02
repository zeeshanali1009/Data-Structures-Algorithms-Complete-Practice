#include <iostream>
using namespace std;

int main() {
    int n = 4; // Size of the square
    char character = 'A'; // Start from 'A'

    for (int i = 0; i < n; ++i) { // Outer loop for rows
        for (int j = 0; j < n; ++j) { // Inner loop for columns
            cout << character << " "; // Print current character
            character++; // Move to next character
        }
        cout << endl; // New line after each row
    }

    return 0;
}
