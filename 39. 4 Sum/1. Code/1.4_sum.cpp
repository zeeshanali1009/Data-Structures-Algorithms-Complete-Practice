#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sorting is necessary for 2-pointer method

    for (int i = 0; i < n - 3; i++) {
        // Skip duplicate for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            // Skip duplicate for j
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    
                    // Skip duplicates for k
                    while (k < l && nums[k] == nums[k + 1]) k++;
                    // Skip duplicates for l
                    while (k < l && nums[l] == nums[l - 1]) l--;

                    k++;
                    l--;
                } 
                else if (sum < target) {
                    k++;
                } 
                else {
                    l--;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);

    for (auto &quad : ans) {
        for (int x : quad) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
