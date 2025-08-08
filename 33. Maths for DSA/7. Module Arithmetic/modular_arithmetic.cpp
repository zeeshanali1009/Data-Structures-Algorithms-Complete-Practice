#include <iostream>
using namespace std;

int main() {
    int a = 100000, b = 200000;
    int mod = 1e9 + 7;

    long long result = (1LL * a * b) % mod;
    cout << result; // Avoid overflow
}
