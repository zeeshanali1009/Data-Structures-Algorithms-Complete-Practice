#include <iostream>
using namespace std;

void updateByReference(int& ref) {
    ref += 5;
}

int main() {
    int x = 10;
    updateByReference(x);   // Now x = 20

    cout << "Updated x: " << x << endl;
    return 0;
}
