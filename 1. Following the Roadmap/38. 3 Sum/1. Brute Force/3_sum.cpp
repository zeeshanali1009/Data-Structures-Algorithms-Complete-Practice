#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, -1, 0, -2, 1};
    int target = 0;
    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
                }
            }
        }
    }
    return 0;
}
