#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2; // q1 -> primary, q2 -> helper

public:
    // Push operation
    void push(int x) {
        // Step 1: move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 2: push new element into q1
        q1.push(x);

        // Step 3: copy all back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop operation
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    // Top element
    int top() {
        if (!q1.empty()) return q1.front();
        return -1; // if empty
    }

    // Check empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20
}
