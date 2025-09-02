#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMissingAndRepeating(const vector<int>& nums) {
    int n = nums.size();
    
    long long sum_n = (long long)n * (n + 1) / 2;                    // expected sum
    long long sum_sq_n = (long long)n * (n + 1) * (2 * n + 1) / 6;    // expected sum of squares
    
    long long sum_arr = 0, sum_sq_arr = 0;
    for (int num : nums) {
        sum_arr += num;
        sum_sq_arr += (long long)num * num;
    }
    
    long long diff = sum_arr - sum_n;         // x - y
    long long sq_diff = sum_sq_arr - sum_sq_n; // x^2 - y^2
    
    long long sum_xy = sq_diff / diff;        // (x + y)
    
    long long x = (diff + sum_xy) / 2;        // repeating
    long long y = x - diff;                   // missing
    
    return { (int)x, (int)y };
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    auto result = findMissingAndRepeating(arr);
    cout << "Repeating number: " << result.first << endl;
    cout << "Missing number: " << result.second << endl;
    
    return 0;
}
