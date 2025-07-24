#include <iostream>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate binomial coefficient
int binomialCoefficient(int n, int r) {
    int num = factorial(n);
    int denom = factorial(r) * factorial(n - r);
    return num / denom;
}

int main() {
    int n, r;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;

    if (r > n) {
        cout << "Invalid input: r cannot be greater than n." << endl;
    } else {
        int result = binomialCoefficient(n, r);
        cout << "Binomial Coefficient C(" << n << ", " << r << ") = " << result << endl;
    }

    return 0;
}
