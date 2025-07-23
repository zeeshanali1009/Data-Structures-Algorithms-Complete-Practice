#include <iostream>
#include <cmath> // for sqrt() function
using namespace std;

int main() {
    int num;
    bool isPrime = true;
    // cout << "Enter a number: ";
    // cin >> num;
    // suppose 
    num  = 10;
    // Edge cases
    if (num <= 1) {
        isPrime = false; // 0 and 1 are not prime
    } else {
        // Loop from 2 to √num to check if num is divisible
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break; // no need to check further
            }
        }
    }
    if (isPrime) {
        cout << num << " is a Prime Number.";
    } else {
        cout << num << " is NOT a Prime Number.";
    }
    return 0;
}
