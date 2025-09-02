#include <bits/stdc++.h>
using namespace std;

void combinationSumHelper(vector<int>& arr, int i, vector<int>& current, int target, vector<vector<int>>& ans) {
    // Base cases
    if (i == arr.size()) {
        if (target == 0) ans.push_back(current);
        return;
    }

    // Option 1: Pick current element (if it doesn't exceed target)
    if (arr[i] <= target) {
        current.push_back(arr[i]);
        combinationSumHelper(arr, i, current, target - arr[i], ans);
        current.pop_back(); // Backtrack
    }

    // Option 2: Skip current element
    combinationSumHelper(arr, i + 1, current, target, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    combinationSumHelper(candidates, 0, current, target, ans);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
