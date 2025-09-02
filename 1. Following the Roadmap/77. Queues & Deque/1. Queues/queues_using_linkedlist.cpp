#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class using Linked List
class Queue {
private:
    Node* front; // points to front node
    Node* rear;  // points to rear node

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* temp = new Node(val);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Peek (front element)
    int peek() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check empty
    bool isEmpty() {
        return (front == NULL);
    }
};

// Driver Code
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after one dequeue: " << q.peek() << endl;

    return 0;
}
