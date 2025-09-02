#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    cout << "Forward: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << "\nReverse: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";

    return 0;
}
