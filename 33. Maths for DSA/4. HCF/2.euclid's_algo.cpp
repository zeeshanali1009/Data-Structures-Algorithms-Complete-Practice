#include <iostream>
using namespace std;

int gcdEuclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cout << gcdEuclid(12, 18); // 6
}
