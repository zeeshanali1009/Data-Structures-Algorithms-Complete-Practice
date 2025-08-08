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

bool isPalindrome(int n) {
    return n == reverseNum(n);
}

int main() {
    cout << isPalindrome(121); // 1 (true)
}
