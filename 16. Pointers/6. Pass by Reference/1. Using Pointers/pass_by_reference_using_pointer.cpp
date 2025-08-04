#include <iostream>
using namespace std;

void updateByPointer(int* p) {
    *p += 5;
}

int main() {
    int x = 10;
    updateByPointer(&x);    // Now x = 15
    cout << "Updated x: " << x << endl;
    return 0;
}
