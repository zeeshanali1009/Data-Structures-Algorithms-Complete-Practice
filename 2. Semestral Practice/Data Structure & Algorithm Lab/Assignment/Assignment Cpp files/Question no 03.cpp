#include <iostream>
using namespace std;
const int MAX_SIZE = 5;
struct CircularQueue {
    int data[MAX_SIZE];
    int front, rear;
    CircularQueue() : front(-1), rear(-1) {}
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)));
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
                data[rear] = value;
            } else if (rear == MAX_SIZE - 1 && front != 0) {
                rear = 0;
                data[rear] = value;
            } else {
                rear++;
                data[rear] = value;
            }
        }
    }
    int dequeue() {
        int value = -1;
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            value = data[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                if (front == MAX_SIZE - 1) {
                    front = 0;
                } else {
                    front++;
                }
            }
        }
        return value;
    }
    int peek() {
        if (!isEmpty()) {
            return data[front];
        } else {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
    }
};
void QueueFunc(CircularQueue& Q1, CircularQueue& Q2) {
    while (!Q1.isEmpty()) {
        int value = Q1.dequeue();
        Q2.enqueue(value);
    }
    while (!Q2.isEmpty() && Q2.peek() != 38) {
        int value = Q2.dequeue();
        Q2.enqueue(value);
    }
}
int main() {
    CircularQueue Q1, Q2;
    Q1.enqueue(50);
    Q1.enqueue(94);
    Q1.enqueue(7);
    Q1.enqueue(11);
    Q1.enqueue(38);
    QueueFunc(Q1, Q2);
    while (!Q2.isEmpty()) {
        cout << Q2.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

