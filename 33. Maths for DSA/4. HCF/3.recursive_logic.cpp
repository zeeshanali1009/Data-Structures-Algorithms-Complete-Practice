#include <iostream>
using namespace std;

int gcdRec(int a, int b) {
    return (b == 0) ? a : gcdRec(b, a % b);
}

int main() {
    cout << gcdRec(12, 18); // 6
}
