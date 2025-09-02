#include <iostream>
using namespace std;
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    // Ternary operator to check even or odd
    (number % 2 == 0) ? cout << "Even" : cout << "Odd";
    return 0;
}
