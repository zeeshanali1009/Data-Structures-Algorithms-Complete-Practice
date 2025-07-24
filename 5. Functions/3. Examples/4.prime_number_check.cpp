#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;  // 0 and 1 are not prime

    for (int i = 2; i * i <= n; i++) {  // Loop till square root of n
        if (n % i == 0)
            return false;  // Not a prime
    }
    return true;  // Prime
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is a Prime Number." << endl;
    else
        cout << num << " is NOT a Prime Number." << endl;

    return 0;
}
