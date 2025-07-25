#include <iostream>
using namespace std;

int main() {
    int a = 5;  // 0101
    int b = 3;  // 0011

    int result = a ^ b;  // 0110 = 6

    cout << "Bitwise XOR of 5 ^ 3 = " << result << endl;
    return 0;
}
