#include <iostream>
using namespace std;

int main() {
    int n = 4; // Number of rows
    char ch = 'A'; // Starting character

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ch;
        }
        cout << endl;
        ch++; // Move to next character
    }

    return 0;
}
