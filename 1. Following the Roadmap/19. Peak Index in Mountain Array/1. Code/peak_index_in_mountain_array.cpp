#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        // If we are in the decreasing part
        if (arr[mid] > arr[mid + 1]) {
            end = mid;  // peak is at mid or to the left
        } else {
            start = mid + 1;  // peak is to the right
        }
    }

    // start == end, both point to the peak
    return start;
}

int main() {
    vector<int> arr = {0, 2, 4, 6, 3, 1};
    int peakIndex = peakIndexInMountainArray(arr);

    cout << "Peak index: " << peakIndex << " (value: " << arr[peakIndex] << ")" << endl;

    return 0;
}
