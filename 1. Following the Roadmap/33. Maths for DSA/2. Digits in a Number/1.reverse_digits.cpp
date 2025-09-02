#include <iostream>
using namespace std;

int reverseNum(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev*10 + n%10;
        n /= 10;
    }
    return rev;
}

int main() {
    cout << reverseNum(1234); // 4321
}
