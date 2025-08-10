#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumPrefix(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount; // stores prefix sum and its frequency
    prefixCount[0] = 1; // sum 0 occurs once initially (for subarrays starting at index 0)

    int prefixSum = 0, count = 0;

    for (int num : nums) {
        prefixSum += num;

        // If prefixSum - k exists, then there’s a subarray ending here with sum k
        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }

        // Store/update current prefix sum in map
        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, -1, 4};
    int k = 3;
    cout << "Count (Prefix Sum + Unordered Map) = " << subarraySumPrefix(nums, k) << endl;
    return 0;
}
