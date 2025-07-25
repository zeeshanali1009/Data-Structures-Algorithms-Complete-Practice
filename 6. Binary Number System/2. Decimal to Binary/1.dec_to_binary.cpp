#include <iostream>
using namespace std;

void dec_to_binary(int decnumber) {
    int ans = 0;
    int pow = 1;
    while (decnumber > 0) {
        int rem = decnumber % 2;
        decnumber = decnumber / 2; // update decnumber
        ans += rem * pow;
        pow *= 10;
    }
    cout << "Decimal into binary form is = " << ans << endl;
}
int main() {
    dec_to_binary(42);
    return 0;
}
