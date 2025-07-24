#include <iostream>
using namespace std;

// Function that uses call by value
void modify(int a, int b) {
    a = a + 10;
    b = b + 20;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 5, y = 10;
    modify(x, y);  // Call by value
    cout << "After function: x = " << x << ", y = " << y << endl;
    return 0;
}
