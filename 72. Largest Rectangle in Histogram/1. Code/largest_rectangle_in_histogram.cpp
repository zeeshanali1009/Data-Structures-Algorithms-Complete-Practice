#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find Nearest Smaller to Left (NSL)
vector<int> nearestSmallerToLeft(vector<int>& heights) {
    stack<int> st;
    vector<int> left(heights.size());
    
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    return left;
}

// Function to find Nearest Smaller to Right (NSR)
vector<int> nearestSmallerToRight(vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    vector<int> right(n);
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }
    return right;
}

// Optimal Largest Rectangle Function
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left = nearestSmallerToLeft(heights);
    vector<int> right = nearestSmallerToRight(heights);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    cout << "Largest Rectangle in Histogram = " 
         << largestRectangleArea(heights) << endl;

    return 0;
}
