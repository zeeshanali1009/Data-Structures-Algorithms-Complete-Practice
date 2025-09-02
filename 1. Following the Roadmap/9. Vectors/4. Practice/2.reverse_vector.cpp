#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
        // Swap v[i] and v[n - 1 - i]
        int temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }

    cout << "Reversed: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
