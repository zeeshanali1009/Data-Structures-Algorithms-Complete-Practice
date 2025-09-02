#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Slow–Fast → find middle
Node* findMiddleSlowFast(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2, slow by 1
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // when fast reaches end, slow is middle
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 6; i++) {
        insert(head, i);
    }

    Node* mid = findMiddleSlowFast(head);
    if (mid) cout << "Middle (Slow-Fast): " << mid->data << endl;
}
