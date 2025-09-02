#include <iostream>
#include <cmath>
using namespace std;

int countDigitsLog(int n) {
    return (n == 0) ? 1 : floor(log10(n)) + 1;
}

int main() {
    cout << countDigitsLog(12345); // 5
}
