#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 2};

    sort(v.begin(), v.end());  // {1, 2, 3, 4}
    reverse(v.begin(), v.end()); // {4, 3, 2, 1}

    next_permutation(v.begin(), v.end());  // next lexicographic permutation

    cout << "Min: " << min(10, 20) << ", Max: " << max(10, 20) << endl;

    return 0;
}
