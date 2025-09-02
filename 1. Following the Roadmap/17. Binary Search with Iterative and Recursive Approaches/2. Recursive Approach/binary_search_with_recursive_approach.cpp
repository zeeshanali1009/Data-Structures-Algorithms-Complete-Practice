#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(vector<int>& arr, int start, int end, int target) {
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, end, target);
    else
        return binarySearchRecursive(arr, start, mid - 1, target);
}

int main() {
    vector<int> arr = {5, 10, 15, 20, 25, 30, 35};
    int target = 10;

    int index = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
