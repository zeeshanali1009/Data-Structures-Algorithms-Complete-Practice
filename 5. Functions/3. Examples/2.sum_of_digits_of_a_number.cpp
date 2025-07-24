#include <iostream>
using namespace std;

// Function to calculate sum of digits
int sumOfDigits(int num) {
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;   // Get last digit
        sum += digit;           // Add to sum
        num /= 10;              // Remove last digit
    }

    return sum;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int result = sumOfDigits(number); // Function call
    cout << "Sum of digits of " << number << " is " << result << endl;

    return 0;
}
