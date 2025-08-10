#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, -1, 0, -2, 1};
    int target = 0;
    int n = arr.size();

    set<vector<int>> triplets;

    for (int i = 0; i < n - 1; i++) {
        unordered_set<int> seen;
        for (int j = i + 1; j < n; j++) {
            int third = target - arr[i] - arr[j];
            if (seen.count(third)) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                triplets.insert(temp);
            }
            seen.insert(arr[j]);
        }
    }

    for (auto &t : triplets) {
        cout << t[0] << " " << t[1] << " " << t[2] << "\n";
    }
    return 0;
}
