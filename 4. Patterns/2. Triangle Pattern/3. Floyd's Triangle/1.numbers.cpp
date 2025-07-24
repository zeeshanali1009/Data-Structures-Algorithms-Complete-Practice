#include <iostream>
using namespace std;

int main() {
    int n = 4;           // Number of rows
    int number = 1;      // Start from 1

    for (int i = 1; i <= n; i++) {          // Outer loop for rows
        for (int j = 1; j <= i; j++) {      // Inner loop for elements in row
            cout << number << " ";          // Print the current number
            number++;                       // Increment the number
        }
        cout << endl;                       // Move to the next line
    }

    return 0;
}
