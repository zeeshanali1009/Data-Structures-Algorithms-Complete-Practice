#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for (int i = 1; i <= n; ++i) {         // Outer loop for rows
        for (int j = 1; j <= n; ++j) {     // Inner loop for columns
            cout << j << " ";              // Print column number
        }
        cout << endl;
    }

    return 0;
}
