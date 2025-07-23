#include <iostream>
using namespace std;
int main() {
    int num;
    unsigned long long factorial = 1; // factorial can be a large number
    cout << "Enter a positive number: ";
    cin >> num;
    // Factorial is not defined for negative numbers
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers.";
    } 
    else {
        // Loop to calculate factorial
        for (int i = 1; i <= num; i++) {
            factorial *= i; // multiply each number to factorial
        }
        cout << "Factorial of " << num << " = " << factorial;
    }
    return 0;
}
