#include <iostream>
using namespace std;

int sumOfN(int n) {
    if (n == 0) {         // Base case
        return 0;
    }
    return n + sumOfN(n - 1); // Recursive call
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Sum of first " << n << " numbers is " << sumOfN(n);
    return 0;
}
