#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

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

    pushBack(head, tail, 10);
    pushBack(head, tail, 20);
    pushBack(head, tail, 30);

    cout << "List after pushBack: ";
    printList(head);

    return 0;
}
