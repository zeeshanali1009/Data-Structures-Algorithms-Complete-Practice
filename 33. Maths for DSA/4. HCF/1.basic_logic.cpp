#include <iostream>
using namespace std;

int gcdBasic(int a, int b) {
    int res = min(a, b);
    while (res > 0) {
        if (a % res == 0 && b % res == 0) break;
        res--;
    }
    return res;
}

int main() {
    cout << gcdBasic(12, 18); // 6
}
