#include <iostream>
using namespace std;
int main() {
    // Outer loop for rows
    for (int i = 1; i <= 3; i++) {
        // Inner loop for columns
        for (int j = 1; j <= 3; j++) {
            cout << "* ";
        }
        cout << endl; // Move to the next line after each row
    }
    return 0;
}
