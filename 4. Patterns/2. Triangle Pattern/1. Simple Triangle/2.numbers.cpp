#include <iostream>
using namespace std;

int main() {
    int n = 5; // Number of rows

    for (int i = 1; i <= n; ++i) {           // Loop for rows
        for (int j = 1; j <= i; ++j) {       // Loop for columns in each row
            cout << i << " ";               // Print current row number
        }
        cout << endl;                        // Move to next line
    }

    return 0;
}
