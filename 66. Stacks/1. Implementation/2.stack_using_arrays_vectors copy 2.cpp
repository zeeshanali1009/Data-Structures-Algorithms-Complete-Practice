#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> arr; // using vector internally
public:
    void push(int x) {
        arr.push_back(x);
    }

    void pop() {
        if (arr.empty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        arr.pop_back();
    }

    int top() {
        if (arr.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr.back();
    }

    bool isEmpty() {
        return arr.empty();
    }

    int size() {
        return arr.size();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30
    st.pop();
    cout << "After pop, Top: " << st.top() << endl; // 20
    cout << "Stack size: " << st.size() << endl;

    return 0;
}
