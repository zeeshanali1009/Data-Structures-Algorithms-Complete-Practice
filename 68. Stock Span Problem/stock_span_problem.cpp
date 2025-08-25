#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to calculate stock span
vector<int> calculateSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n); 
    stack<int> st;  // store indices

    for (int i = 0; i < n; i++) {
        // Pop all elements smaller or equal to price[i]
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        // If stack empty → no greater element on left
        if (st.empty()) {
            span[i] = i + 1;  
        }
        else {
            span[i] = i - st.top();
        }

        // Push current index
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(price);

    cout << "Price: ";
    for (int p : price) cout << p << " ";
    cout << endl;

    cout << "Span : ";
    for (int s : result) cout << s << " ";
    cout << endl;

    return 0;
}
