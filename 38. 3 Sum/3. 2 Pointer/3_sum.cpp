#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, -1, 0, -2, 1};
    int target = 0;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicates

        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target) {
                cout << arr[i] << " " << arr[left] << " " << arr[right] << "\n";
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++; right--;
            } 
            else if (sum < target) left++;
            else right--;
        }
    }
    return 0;
}
