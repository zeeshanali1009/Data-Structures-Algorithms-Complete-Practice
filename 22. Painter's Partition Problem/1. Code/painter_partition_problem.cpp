#include <iostream>
using namespace std;

// 🔍 Check if it's possible to paint all boards with maxTime
bool isPossible(int arr[], int n, int k, int maxTime) {
    int painterCount = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) return false;

        if (currentTime + arr[i] <= maxTime) {
            currentTime += arr[i];
        } else {
            painterCount++;
            currentTime = arr[i];

            if (painterCount > k)
                return false;
        }
    }
    return true;
}

// 🧮 Main binary search function
int painterPartition(int arr[], int n, int k) {
    int start = 0, end = 0;

    // Calculate search space
    for (int i = 0; i < n; i++) {
        if (arr[i] > start)
            start = arr[i]; // largest single board
        end += arr[i];     // total length of all boards
    }

    int answer = -1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (isPossible(arr, n, k, mid)) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return answer;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int k = 2;

    int result = painterPartition(boards, n, k);

    if (result == -1)
        cout << "Not enough painters.\n";
    else
        cout << "Minimum time to paint all boards = " << result << endl;
    return 0;
}
