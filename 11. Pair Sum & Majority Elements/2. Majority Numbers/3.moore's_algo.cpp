#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int>& nums) {
    int candidate = -1;
    int freq = 0;

    // Step 1: Find candidate
    for (int i = 0; i < nums.size(); i++) {
        if (freq == 0) {
            candidate = nums[i];
            freq = 1;
        } else if (nums[i] == candidate) {
            freq++;
        } else {
            freq--;
        }
    }

    // Step 2: Verify candidate
    freq = 0;
    for (int num : nums) {
        if (num == candidate) freq++;
    }

    if (freq > nums.size() / 2) {
        return candidate;
    } else {
        return -1;  // No majority element
    }
}

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    int result = findMajorityElement(arr);

    if (result != -1)
        cout << "Majority element is: " << result << endl;
    else
        cout << "No majority element found" << endl;

    return 0;
}
