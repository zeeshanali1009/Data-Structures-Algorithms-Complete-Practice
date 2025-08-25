#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack not empty → top is the next greater
        if (!st.empty()) {
            nge[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreater(arr);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "NGE  : ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
