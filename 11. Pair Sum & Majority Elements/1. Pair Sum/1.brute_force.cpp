#include <iostream>
#include <vector>
using namespace std;

bool pairSumBruteForce(vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << target << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    if (!pairSumBruteForce(arr, target)) {
        cout << "No pair found." << endl;
    }

    return 0;
}
