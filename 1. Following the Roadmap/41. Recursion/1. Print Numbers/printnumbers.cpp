#include <iostream>
using namespace std;

void printnumbers(int n) {
    if (n == 0)  // Base case
        return;
    printnumbers(n - 1); // Recursive call first
    cout << n << " ";      // Print after recursion
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    printnumbers(n);
    return 0;
}
