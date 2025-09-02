#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int size;
    int front, rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue
    void enqueue(int val) {
        // check full
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "Queue is full\n";
            return;
        }

        // first element
        if (front == -1) {
            front = rear = 0;
            arr[rear] = val;
        }
        else {
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
    }

    // Dequeue
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        // only one element
        if (front == rear) {
            cout << "Dequeued: " << arr[front] << endl;
            front = rear = -1;
        }
        else {
            cout << "Dequeued: " << arr[front] << endl;
            front = (front + 1) % size;
        }
    }

    // Get front element
    int getFront() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (rear == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Check empty
    bool isEmpty() {
        return (front == -1);
    }
};

// Driver
int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front: " << q.getFront() << endl; // 10
    cout << "Rear: " << q.getRear() << endl;   // 40

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    cout << "Front: " << q.getFront() << endl; // 30
    cout << "Rear: " << q.getRear() << endl;   // 60

    return 0;
}
