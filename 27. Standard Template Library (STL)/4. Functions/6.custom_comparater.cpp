#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom function to sort in descending order
bool compare(int a, int b) {
    return a > b;  // descending
}

int main() {
    vector<int> v = {10, 3, 5, 8};

    sort(v.begin(), v.end(), compare);  // using custom function

    for (int x : v) cout << x << " ";  // Output: 10 8 5 3

    return 0;
}
