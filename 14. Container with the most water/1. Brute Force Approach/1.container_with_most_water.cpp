#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxAreaBruteForce(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int width = j - i;
            int h = min(height[i], height[j]);
            int area = width * h;
            maxWater = max(maxWater, area);
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Water Container (Brute Force): " << maxAreaBruteForce(height) << endl;
    return 0;
}
