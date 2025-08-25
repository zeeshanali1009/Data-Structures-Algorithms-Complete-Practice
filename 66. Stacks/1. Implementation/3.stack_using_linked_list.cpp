#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
    Node* topNode;
    int count;
public:
    Stack() : topNode(nullptr), count(0) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.push(25);

    cout << "Top element: " << st.top() << endl; // 25
    st.pop();
    cout << "After pop, Top: " << st.top() << endl; // 15
    cout << "Stack size: " << st.size() << endl;

    return 0;
}
