#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // Avoid overflow
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;  // Target not found
}

int main() {
    vector<int> arr = {3, 7, 11, 18, 24, 35, 47};
    int target = 24;

    int index = binarySearchIterative(arr, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
