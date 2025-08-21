#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Delete head node
void deleteHead(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == head) { // single node
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = head->next;
    head = head->next;
    delete temp;
}
// Insert at tail
void insertTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void printList(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert manually for testing
    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);

    cout << "Original list: ";
    printList(head);

    deleteHead(head);
    cout << "After deleteHead: ";
    printList(head);

    return 0;
}
