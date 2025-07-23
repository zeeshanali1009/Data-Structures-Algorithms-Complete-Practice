#include <iostream>
using namespace std;
int main() {
    int a = 10, b = 3;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;     // Integer division
    cout << "a % b = " << a % b << endl;
    // In case of division
    // a / b (both int) results in integer division, so 10 / 3 becomes 3.
    // For decimal division, use float/double:
    // Integer division example
    int y1 = 9, z = 2;
    cout << "y1 / z = " << y1 / z << endl;  // Output: 4
    // Decimal division using float
    float x = 10.0, y2 = 3.0;
    cout << "x / y2 = " << x / y2 << endl;  // Output: 3.33333
    return 0;
}



