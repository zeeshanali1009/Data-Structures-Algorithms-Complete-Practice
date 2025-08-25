#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);   // Initialize answer with -1
    stack<int> st;            // Stack to keep indices

    // Traverse from (2n-1) → 0
    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;  // circular index

        // Pop smaller or equal elements
        while (!st.empty() && nums[st.top()] <= nums[idx]) {
            st.pop();
        }

        // Assign answer for first pass only
        if (i < n) {
            ans[idx] = st.empty() ? -1 : nums[st.top()];
        }

        // Push current index
        st.push(idx);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
