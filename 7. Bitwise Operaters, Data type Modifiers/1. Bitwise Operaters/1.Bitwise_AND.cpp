#include <iostream>
using namespace std;

int main() {
    int a = 5;  // Binary: 0101
    int b = 3;  // Binary: 0011

    int result = a & b;  // 0001 = 1

    cout << "Bitwise AND of 5 & 3 = " << result << endl;
    return 0;
}
