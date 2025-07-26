#include <iostream>
#include <vector>
using namespace std;

int majorityBruteForce(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > n / 2)
            return arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 2, 1, 1, 2};
    int majority = majorityBruteForce(arr);
    if (majority != -1)
        cout << "Majority element: " << majority << endl;
    else
        cout << "No majority element found." << endl;
}
