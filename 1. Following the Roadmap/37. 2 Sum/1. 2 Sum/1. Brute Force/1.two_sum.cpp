#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {                  // pick first element
        for (int j = i + 1; j < n; j++) {          // pick second element
            if (nums[i] + nums[j] == target) {
                return {i, j}; // return the indexes
            }
        }
    }
    return {}; // no solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumBruteForce(nums, target);
    if (!result.empty()) {
        cout << "Indexes: " << result[0] << " and " << result[1] << endl;
    }
}
