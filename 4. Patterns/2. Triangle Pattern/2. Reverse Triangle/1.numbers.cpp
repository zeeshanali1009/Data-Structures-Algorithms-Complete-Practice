#include <iostream>
using namespace std;

int main() {
    int n = 4; // Number of rows

    for (int i = 1; i <= n; i++) {          // Outer loop for rows (1 to n)
        for (int j = i; j >= 1; j--) {      // Inner loop for reverse printing
            cout << j << " ";               // Print decreasing numbers
        }
        cout << endl;                       // Move to next line
    }

    return 0;
}
