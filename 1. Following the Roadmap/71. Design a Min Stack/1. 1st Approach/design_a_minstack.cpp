#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st, minSt;

public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }

    void pop() {
        if (st.empty()) return;
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        if (st.empty()) return -1; // stack empty case
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) return -1; // stack empty case
        return minSt.top();
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(2);
    ms.push(10);
    ms.push(1);

    cout << "Current Min: " << ms.getMin() << endl; // 1
    ms.pop(); // removes 1
    cout << "Top: " << ms.top() << endl;           // 10
    cout << "Current Min: " << ms.getMin() << endl; // 2

    return 0;
}
