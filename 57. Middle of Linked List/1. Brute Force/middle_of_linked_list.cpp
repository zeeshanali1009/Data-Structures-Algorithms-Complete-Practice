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

// Brute Force → find middle using size
Node* findMiddleBrute(Node* head) {
    if (!head) return nullptr;

    // Step 1: find size
    int size = 0;
    Node* temp = head;
    while (temp) {
        size++;
        temp = temp->next;
    }

    // Step 2: (size+1)/2 node
    int mid = (size + 1) / 2;
    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 7; i++) {
        insert(head, i);
    }

    Node* mid = findMiddleBrute(head);
    if (mid) cout << "Middle (Brute Force): " << mid->data << endl;
}
