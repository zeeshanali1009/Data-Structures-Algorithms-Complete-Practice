#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterWithMap(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nge; // map element -> next greater
    stack<int> st;

    // Traverse nums2 to fill the map
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        nge[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    // Build result for nums1 using the map
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nge[num]);
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterWithMap(nums1, nums2);

    cout << "Result: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
