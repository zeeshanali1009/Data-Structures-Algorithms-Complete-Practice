#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2; // s1 -> primary, s2 -> helper

public:
    // Push operation
    void push(int x) {
        // Step 1: move everything from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: push element into s1
        s1.push(x);

        // Step 3: move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Pop operation
    void pop() {
        if (!s1.empty()) {
            s1.pop();
        }
    }

    // Front element
    int front() {
        if (!s1.empty()) return s1.top();
        return -1; // if empty
    }

    // Check empty
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << endl; // 1
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // 2
}
