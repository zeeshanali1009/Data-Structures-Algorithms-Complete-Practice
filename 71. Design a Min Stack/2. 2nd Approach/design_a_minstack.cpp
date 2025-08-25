#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;   // store normal + encoded values
    long long minval;      // current minimum

public:
    MinStack() {
        minval = 0;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minval = val;
        } else {
            if (val < minval) {
                // encode value before pushing
                st.push(2LL * val - minval);
                minval = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        long long topVal = st.top();
        st.pop();

        if (topVal < minval) {
            // decode old minval
            minval = 2LL * minval - topVal;
        }
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        long long topVal = st.top();
        if (topVal < minval) {
            return (int)minval;
        }
        return (int)topVal;
    }

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return (int)minval;
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(2);
    ms.push(10);
    ms.push(1);

    cout << "Min: " << ms.getMin() << endl; // 1
    ms.pop();
    cout << "Min: " << ms.getMin() << endl; // 2
    cout << "Top: " << ms.top() << endl;    // 10
    ms.pop();
    cout << "Min: " << ms.getMin() << endl; // 2

    return 0;
}
