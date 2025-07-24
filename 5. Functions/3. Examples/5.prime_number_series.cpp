#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int limit;
    cout << "Enter the upper limit: ";
    cin >> limit;

    cout << "Prime numbers up to " << limit << " are: ";

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i))
            cout << i << " ";
    }

    cout << endl;
    return 0;
}
