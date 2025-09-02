#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Pop from front
void popFront(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to pop.\n";
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}
// Push at back
void pushBack(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Create list
    head = new Node(10);
    tail = head;
    pushBack(head, tail, 20); // optional if you want pushBack defined here

    cout << "Original list: ";
    printList(head);

    popFront(head, tail);
    cout << "After popFront: ";
    printList(head);

    return 0;
}
