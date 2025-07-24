#include <iostream>
using namespace std;

int main() {
    int n = 4; // Number of rows

    for (int i = 1; i <= n; i++) {              // Rows from 1 to n
        for (int j = n; j >= i; j--) {          // Print decreasing number of times
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
