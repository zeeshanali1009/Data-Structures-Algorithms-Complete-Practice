#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at end
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

// 1. Detect if loop exists using slow-fast pointers
bool detectLoop(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // loop detected
        }
    }
    return false;
}

// 2. Find the starting point of loop
Node* getStartingNode(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // First detect meeting point
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Reset slow to head, keep fast at meeting point
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // starting node of loop
        }
    }
    return nullptr;
}

// 3. Remove the loop
void removeLoop(Node* head) {
    Node* startOfLoop = getStartingNode(head);
    if (!startOfLoop) return; // no loop

    Node* temp = startOfLoop;

    // traverse till node before startOfLoop
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = nullptr; // break the loop
}

// Utility: print list (safe, no infinite loop)
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 6; i++) {
        insert(head, i);
    }

    // Manually create a loop for testing (tail->next = node 3)
    head->next->next->next->next->next->next = head->next->next;

    // Detect loop
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;

        Node* start = getStartingNode(head);
        cout << "Loop starts at node with value: " << start->data << endl;

        removeLoop(head);
        cout << "Loop removed successfully." << endl;
    } else {
        cout << "No loop found." << endl;
    }

    cout << "Final Linked List after removal: ";
    printList(head);

    return 0;
}
