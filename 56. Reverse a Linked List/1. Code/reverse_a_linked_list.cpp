#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* head = nullptr;

// Insert node at the back
void pushBack(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Reverse linked list (using current pointer logic from notes)
Node* reverseList(Node* head) {
    Node* prev = nullptr;     // initialization
    Node* curr = head;        // initialization
    Node* next = nullptr;     // initialization

    while (curr != nullptr) {
        next = curr->next;    // Step 1: preserve next
        curr->next = prev;    // Step 2: reverse pointer
        prev = curr;          // Step 3: move prev forward
        curr = next;          // Step 4: move curr forward
    }
    return prev;  // new head
}

int main() {
    // Example: build list
    pushBack(10);
    pushBack(20);
    pushBack(30);
    pushBack(40);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
