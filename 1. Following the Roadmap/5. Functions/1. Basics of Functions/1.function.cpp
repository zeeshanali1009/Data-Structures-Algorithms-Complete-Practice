#include <iostream>
using namespace std;

// Step 1: Declaration
int add(int, int);

int main() {
    // Step 3: Call
    int sum = add(10, 20);
    cout << "Sum: " << sum << endl;
    return 0;
}

// Step 2: Definition
int add(int x, int y) {
    return x + y;
}
