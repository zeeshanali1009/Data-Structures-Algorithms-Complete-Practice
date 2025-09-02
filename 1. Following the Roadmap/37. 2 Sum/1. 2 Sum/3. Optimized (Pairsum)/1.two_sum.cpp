#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumHashing(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // found
        }
        mp[nums[i]] = i; // store value with index
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumHashing(nums, target);
    if (!result.empty()) {
        cout << "Indexes: " << result[0] << " and " << result[1] << endl;
    }
}
