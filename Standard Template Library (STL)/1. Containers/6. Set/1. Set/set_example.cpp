#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s = {10, 20, 20, 30};
    cout << "Set: ";
    for (int x : s) cout << x << " ";  // Output: 10 20 30

    return 0;
}
