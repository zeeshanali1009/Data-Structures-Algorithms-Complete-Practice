#include <iostream>
using namespace std;
void binary_to_dec(int binnumber) {
    int ans = 0;
    int pow = 1;
    while (binnumber > 0) {
        int rem = binnumber % 10;      // Get the last digit (0 or 1)
        ans += rem * pow;              // Multiply it by power of 2
        binnumber /= 10;               // Remove the last digit
        pow *= 2;                      // Increase power of 2
    }
    cout << "Binary into decimal form is = " << ans << endl;
}
int main() {
    binary_to_dec(101010);
    return 0;
}
