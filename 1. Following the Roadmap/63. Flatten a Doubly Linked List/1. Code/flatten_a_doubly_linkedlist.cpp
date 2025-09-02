#include <bits/stdc++.h>
using namespace std;

// Node definition for multilevel doubly linked list
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* nodeNext = curr->next;

                // Flatten child list recursively
                curr->next = flatten(curr->child);
                curr->next->prev = curr;

                // Remove child pointer
                curr->child = nullptr;

                // Move to the tail of the child list
                Node* temp = curr->next;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }

                // Connect tail of child list with original next
                if (nodeNext != nullptr) {
                    temp->next = nodeNext;
                    nodeNext->prev = temp;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

// Utility function to print list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Example:
    // 1 - 2 - 3 - 4
    //         |
    //         5 - 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    // Add child to node 3
    Node* child = new Node(5);
    child->next = new Node(6);
    child->next->prev = child;
    head->next->next->child = child;

    Solution sol;
    Node* flatHead = sol.flatten(head);

    cout << "Flattened List: ";
    printList(flatHead);

    return 0;
}
