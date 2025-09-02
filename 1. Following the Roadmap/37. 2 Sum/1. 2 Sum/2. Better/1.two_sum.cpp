#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSumTwoPointers(vector<int>& nums, int target) {
    vector<pair<int,int>> arr; // value, index
    for (int i = 0; i < nums.size(); i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end()); // sort by value

    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left].first + arr[right].first;
        if (sum == target) {
            return {arr[left].second, arr[right].second}; // return original indexes
        }
        else if (sum < target) left++;
        else right--;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumTwoPointers(nums, target);
    if (!result.empty()) {
        cout << "Indexes: " << result[0] << " and " << result[1] << endl;
    }
}
