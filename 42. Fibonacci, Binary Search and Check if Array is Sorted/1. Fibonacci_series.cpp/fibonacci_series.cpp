#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0)   // Base case 1
        return 0;
    if (n == 1)   // Base case 2
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive step
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}
