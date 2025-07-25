#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3, c = 2;

    int result = ((a + b) * c > 10) && ((a & b) == (a ^ b)) ? (a += 2) : (b *= 2);

    cout << "a = " << a << ", b = " << b << ", result = " << result << endl;

    return 0;
}
