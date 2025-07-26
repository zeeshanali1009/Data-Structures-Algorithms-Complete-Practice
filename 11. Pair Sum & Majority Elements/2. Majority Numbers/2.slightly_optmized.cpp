#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majoritySortOptimized(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // O(n log n)

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
            if (count > n / 2)
                return arr[i];
        } else {
            count = 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 3, 4, 2, 3, 3, 3};
    int majority = majoritySortOptimized(arr);
    if (majority != -1)
        cout << "Majority element: " << majority << endl;
    else
        cout << "No majority element found." << endl;
}
