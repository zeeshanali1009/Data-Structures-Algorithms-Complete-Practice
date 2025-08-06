#include <iostream>
#include <set>
#include <multiset>
using namespace std;

int main() {
    multiset<int> ms = {10, 10, 20};
    cout << "\nMultiset: ";
    for (int x : ms) cout << x << " ";  // Output: 10 10 20

    return 0;
}
