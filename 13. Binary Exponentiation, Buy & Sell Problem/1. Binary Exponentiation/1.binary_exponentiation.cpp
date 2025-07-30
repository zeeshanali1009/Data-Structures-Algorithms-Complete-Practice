#include <iostream>
using namespace std;

long long binaryExponentiation(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) {
            result *= a;       // If b is odd, multiply result by current a
        }
        a *= a;                // Square the base
        b >>= 1;               // Divide b by 2
    }
    return result;
}

int main() {
    long long a, b;
    cout << "Enter base and exponent: ";
    cin >> a >> b;
    
    cout << "Result: " << binaryExponentiation(a, b) << endl;
    return 0;
}
