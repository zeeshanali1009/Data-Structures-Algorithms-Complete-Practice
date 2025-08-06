#include <iostream>
using namespace std;

void greet() {
    cout << "Hello from a function!" << endl;
}

void add(int a, int b) {
    cout << "Sum = " << (a + b) << endl;
}

int main() {
    greet();
    add(5, 10);
    return 0;
}
