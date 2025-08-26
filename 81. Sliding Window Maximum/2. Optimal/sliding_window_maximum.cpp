#include <bits/stdc++.h>
using namespace std;

// Optimal: O(n) using deque
vector<int> slidingWindowOptimal(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;
    int n = nums.size();

    // 1. Process first window
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result.push_back(nums[dq.front()]);

    // 2. Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove indices that are out of current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove all smaller elements than current
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        result.push_back(nums[dq.front()]);
    }

    return result;
}

// Driver code
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = slidingWindowOptimal(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
