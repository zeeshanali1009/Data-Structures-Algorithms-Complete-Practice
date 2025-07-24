#include <iostream>
using namespace std;

int main() {
    int n = 4; // Size of the square

    for (int i = 1; i <= n; ++i) {         // Outer loop for rows
        for (int j = 1; j <= n; ++j) {     // Inner loop for columns
            cout << "* ";                  // Print asterisk with space
        }
        cout << endl;                      // Move to next line after each row
    }

    return 0;
}
