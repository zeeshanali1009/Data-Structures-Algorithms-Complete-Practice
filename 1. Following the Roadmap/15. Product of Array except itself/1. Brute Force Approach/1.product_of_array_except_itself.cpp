#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelfBruteForce(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        int product = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                product *= nums[j];
            }
        }
        result[i] = product;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelfBruteForce(nums);

    cout << "Brute Force Product Except Self: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
