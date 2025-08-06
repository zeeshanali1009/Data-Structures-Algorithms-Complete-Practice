#include <iostream>
using namespace std;

void update(int &x) {
    x += 10;
}

int main() {
    int a = 5;
    update(a);
    cout << "Updated value: " << a << endl;  // Output: 15
    return 0;
}
