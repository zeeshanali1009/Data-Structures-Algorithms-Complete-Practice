#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int temp = n;
    int digits = floor(log10(n)) + 1;
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }
    return sum == temp;
}

int main() {
    cout << isArmstrong(153); // 1 (true)
}
