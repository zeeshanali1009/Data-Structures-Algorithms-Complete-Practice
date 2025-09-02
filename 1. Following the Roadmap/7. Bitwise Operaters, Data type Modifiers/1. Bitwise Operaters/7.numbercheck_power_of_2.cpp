#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    int power = 1;

    // Keep left shifting until power >= n
    while (power <= n) {
        if (power == n)
            return true;
        power = power << 1;  // Multiply by 2 using left shift
    }

    return false;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPowerOfTwo(number)) {
        cout << number << " is a power of 2." << endl;
    } else {
        cout << number << " is NOT a power of 2." << endl;
    }

    return 0;
}
