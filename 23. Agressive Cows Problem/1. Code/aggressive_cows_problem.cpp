#include <iostream>
#include <algorithm>
using namespace std;

// 🔍 Check if it's possible to place cows with at least 'minDist' between them
bool isPossible(int arr[], int n, int c, int minDist) {
    int cows = 1;                  // 1st cow is always placed at arr[0]
    int last_stall = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last_stall >= minDist) {
            cows++;                // place cow
            last_stall = arr[i];  // update position

            if (cows == c)
                return true;       // All cows placed successfully
        }
    }

    return false;  // Not enough cows could be placed
}

// 🧠 Main binary search function
int aggressiveCows(int arr[], int n, int c) {
    sort(arr, arr + n);  // ✅ Always sort stall positions

    int start = 1;
    int end = arr[n - 1] - arr[0];
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, c, mid)) {
            ans = mid;        // Valid distance found, try larger
            start = mid + 1;
        } else {
            end = mid - 1;    // Try smaller distance
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 8, 4, 9};
    int n = 5;
    int cows = 3;

    int result = aggressiveCows(arr, n, cows);
    cout << "Maximum minimum distance between cows = " << result << endl;

    return 0;
}
