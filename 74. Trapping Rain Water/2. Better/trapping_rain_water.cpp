#include <iostream>
#include <vector>
using namespace std;

// Better Approach (prefix arrays)
// Time: O(n), Space: O(n)
int trapBetter(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> lmax(n), rmax(n);

    lmax[0] = height[0];
    for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i - 1], height[i]);
    }

    rmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rmax[i] = max(rmax[i + 1], height[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(lmax[i], rmax[i]) - height[i];
    }
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Better: " << trapBetter(height) << endl;
    return 0;
}
