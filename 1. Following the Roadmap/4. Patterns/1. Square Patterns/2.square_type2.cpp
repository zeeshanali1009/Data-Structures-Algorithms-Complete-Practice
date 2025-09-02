#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int num =1;
    for (int i = 0; i < n; i++) {         // Outer loop for rows
        for (int j = 0; j < n; j++) {     // Inner loop for columns
            cout << num << " ";              // Print column number
            num++;
        }
        cout << endl;
    }

    return 0;
}
