#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // Square each element using for_each and lambda
    for_each(v.begin(), v.end(), [](int x) {
        cout << x * x << " ";
    });

    return 0;
}
