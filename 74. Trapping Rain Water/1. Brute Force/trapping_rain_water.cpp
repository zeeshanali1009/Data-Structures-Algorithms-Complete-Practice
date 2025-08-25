#include <iostream>
#include <vector>
using namespace std;

int trapBrute(vector<int>& height) {
    int n = height.size();
    int water = 0;

    for (int i = 0; i < n; i++) {
        int lmax = height[i], rmax = height[i];

        // find max to left
        for (int j = 0; j < i; j++) {
            lmax = max(lmax, height[j]);
        }

        // find max to right
        for (int j = i + 1; j < n; j++) {
            rmax = max(rmax, height[j]);
        }

        water += min(lmax, rmax) - height[i];
    }
    return water;
}
