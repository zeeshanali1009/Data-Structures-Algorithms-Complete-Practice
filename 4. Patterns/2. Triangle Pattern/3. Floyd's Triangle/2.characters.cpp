#include <iostream>
using namespace std;

int main() {
    int n = 4;                 // Number of rows
    char ch = 'A';             // Start from 'A'

    for (int i = 1; i <= n; i++) {          // Outer loop for rows
        for (int j = 1; j <= i; j++) {      // Inner loop for elements in row
            cout << ch << " ";              // Print current character
            ch++;                           // Move to next alphabet
        }
        cout << endl;                       // Move to next line
    }

    return 0;
}
