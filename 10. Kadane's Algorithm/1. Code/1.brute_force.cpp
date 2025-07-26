#include <iostream>
#include <vector>
#include <climits>  // for INT_MIN
using namespace std;

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++) {
        int currentSum = 0;
        for (int end = start; end < n; end++) {
            currentSum += arr[end];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}
