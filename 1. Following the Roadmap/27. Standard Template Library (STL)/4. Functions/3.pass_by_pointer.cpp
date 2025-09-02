#include <iostream>
using namespace std;

void update(int* ptr) {
    *ptr += 10;
}

int main() {
    int a = 20;
    update(&a);
    cout << "Updated value: " << a << endl;  // Output: 30
    return 0;
}
