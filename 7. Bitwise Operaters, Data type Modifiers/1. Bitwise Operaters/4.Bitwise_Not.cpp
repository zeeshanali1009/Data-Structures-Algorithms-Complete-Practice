#include <iostream>
using namespace std;

int main() {
    int a = 5;  // 0101

    int result = ~a;  // 2's complement => -(a+1) = -6

    cout << "Bitwise NOT of 5 = " << result << endl;
    return 0;
}
