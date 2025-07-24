#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {             // Outer loop controls rows
        for (int j = 0; j <= i; j++) {        // Inner loop prints '*' i+1 times
            cout << "* ";
        }
        cout << endl;                         // Move to next line after each row
    }

    return 0;
}
