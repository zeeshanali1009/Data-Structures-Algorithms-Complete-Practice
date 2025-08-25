#include <iostream>
#include <vector>
using namespace std;

// Optimal Two Pointers Approach
// Time: O(n), Space: O(1)
int trapOptimal(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int lmax = 0, rmax = 0, water = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= lmax) {
                lmax = height[left];
            } else {
                water += lmax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rmax) {
                rmax = height[right];
            } else {
                water += rmax - height[right];
            }
            right--;
        }
    }
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Optimal: " << trapOptimal(height) << endl;
    return 0;
}
