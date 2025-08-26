#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n*k)
vector<int> slidingWindowBruteForce(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i <= n - k; i++) {
        int windowMax = nums[i];
        for (int j = i; j < i + k; j++) {
            windowMax = max(windowMax, nums[j]);
        }
        result.push_back(windowMax);
    }
    return result;
}
