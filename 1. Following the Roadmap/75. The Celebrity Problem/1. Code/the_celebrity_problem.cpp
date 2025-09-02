#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Finds celebrity using stack method.
// arr[i][j] == 1 means i knows j.
int findCelebrity(const vector<vector<int>>& arr) {
    int n = arr.size();
    if (n == 0) return -1;

    stack<int> st;
    // 1) push everyone onto stack
    for (int i = 0; i < n; ++i) st.push(i);

    // 2) reduce to one candidate
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if (arr[a][b] == 1) {
            // a knows b => a cannot be celebrity, b may be
            st.push(b);
        } else {
            // a does not know b => b cannot be celebrity, a may be
            st.push(a);
        }
    }

    // If nobody left
    if (st.empty()) return -1;

    int cand = st.top(); // potential celebrity

    // 3) Verify candidate:
    //    - cand should not know anyone: arr[cand][j] == 0 for all j != cand
    //    - everyone else should know cand: arr[i][cand] == 1 for all i != cand
    for (int j = 0; j < n; ++j) {
        if (j == cand) continue;
        if (arr[cand][j] == 1) { // candidate knows j -> not celebrity
            return -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == cand) continue;
        if (arr[i][cand] == 0) { // someone doesn't know candidate -> not celebrity
            return -1;
        }
    }

    return cand; // valid celebrity
}

int main() {
    // Example:
    // Person 0 knows 1 and 2
    // Person 1 knows nobody (candidate celebrity)
    // Person 2 knows 1
    vector<vector<int>> arr = {
        {0,1,1},
        {0,0,0},
        {0,1,0}
    };

    int celeb = findCelebrity(arr);
    if (celeb == -1) cout << "No celebrity found\n";
    else cout << "Celebrity is person: " << celeb << "\n";

    return 0;
}
