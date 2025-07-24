#include <iostream>
using namespace std;

int main() {
    int n = 4; // Size of the square

    for (int i = 0; i < n; ++i) { 
        char chracter = 'A';                           // Outer loop for rows
        for (int j = 0; j < n; j++) {     // Inner loop for columns
            cout << chracter;                  // Print asterisk with space
            chracter++;
        }
        cout << endl;                      // Move to next line after each row
    }

    return 0;
}
 