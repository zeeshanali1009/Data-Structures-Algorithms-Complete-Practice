#include <iostream>
#include <vector>
using namespace std;

bool pairSumTwoPointers(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            cout << "Pair found: " << arr[left] << " + " << arr[right] << " = " << target << endl;
            return true;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 8, 9};  // MUST be sorted
    int target = 10;

    if (!pairSumTwoPointers(arr, target)) {
        cout << "No pair found." << endl;
    }

    return 0;
}
