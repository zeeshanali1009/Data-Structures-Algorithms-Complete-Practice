#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Pop from back
void popBack(Node*& head, Node*& tail) {
    if (tail == nullptr) {
        cout << "List is empty. Nothing to pop.\n";
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
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

    // Create list manually
    head = new Node(10);
    Node* second = new Node(20);
    head->next = second;
    second->prev = head;
    tail = second;

    cout << "Original list: ";
    printList(head);

    popBack(head, tail);
    cout << "After popBack: ";
    printList(head);

    return 0;
}
