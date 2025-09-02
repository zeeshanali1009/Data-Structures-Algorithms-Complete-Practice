#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    // Insert at front
    void insertFront(int val) {
        Node* temp = new Node(val);
        if (front == NULL) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    // Insert at rear
    void insertRear(int val) {
        Node* temp = new Node(val);
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    // Delete from front
    void deleteFront() {
        if (front == NULL) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != NULL) front->prev = NULL;
        else rear = NULL; // only one element was there
        delete temp;
    }

    // Delete from rear
    void deleteRear() {
        if (rear == NULL) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear != NULL) rear->next = NULL;
        else front = NULL; // only one element was there
        delete temp;
    }

    // Get front
    int getFront() {
        if (front == NULL) {
            cout << "Deque is empty\n";
            return -1;
        }
        return front->data;
    }

    // Get rear
    int getRear() {
        if (rear == NULL) {
            cout << "Deque is empty\n";
            return -1;
        }
        return rear->data;
    }

    // Check empty
    bool isEmpty() {
        return (front == NULL);
    }
};

// Driver Code
int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);

    cout << "Front: " << dq.getFront() << endl; // 5
    cout << "Rear: " << dq.getRear() << endl;   // 20

    dq.deleteFront();
    cout << "Front after deleteFront: " << dq.getFront() << endl; // 10

    dq.deleteRear();
    cout << "Rear after deleteRear: " << dq.getRear() << endl; // 10

    return 0;
}
