#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[start] <= nums[mid]) {
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;  // Target in left half
            else
                start = mid + 1;  // Target in right half
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[end])
                start = mid + 1;  // Target in right half
            else
                end = mid - 1;  // Target in left half
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = searchInRotatedArray(nums, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
