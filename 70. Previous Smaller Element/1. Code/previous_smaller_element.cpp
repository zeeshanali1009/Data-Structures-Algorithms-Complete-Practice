    #include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmaller(vector<int>& arr) {
    stack<int> st;
    vector<int> ans;

    for (int x : arr) {
        while (!st.empty() && st.top() >= x) {
            st.pop();
        }
        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(x);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = previousSmaller(arr);

    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
