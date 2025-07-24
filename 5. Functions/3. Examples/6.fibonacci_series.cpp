#include <iostream>
using namespace std;

// Function to print Fibonacci series up to n terms
void printFibonacci(int n) {
    int a = 0, b = 1;
    cout << "Fibonacci Series up to " << n << " terms: ";

    for (int i = 1; i <= n; ++i) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;

    printFibonacci(terms);

    return 0;
}
