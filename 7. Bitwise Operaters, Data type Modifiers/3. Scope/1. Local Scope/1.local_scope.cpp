#include <iostream>
using namespace std;

void demoFunction() {
    int funcVar = 200; // Local to this function
    cout << "Inside function: funcVar = " << funcVar << endl;
}

int main() {
    int a = 10; // Local to main()

    if (a > 5) {
        int b = 20; // Local to if-block
        cout << "Inside if block: b = " << b << endl;
    }
    // cout << b; // Error: b not accessible here

    for (int i = 0; i < 3; i++) {
        cout << "Inside loop: i = " << i << endl;
    }
    // cout << i; // Error: i not accessible here

    demoFunction(); // Calls another function

    return 0;
}
