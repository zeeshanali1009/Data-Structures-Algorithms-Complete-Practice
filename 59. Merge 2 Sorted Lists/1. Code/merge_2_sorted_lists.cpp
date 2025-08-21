#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted lists
ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
    // Base cases
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    // Recursive case
    if (h1->val <= h2->val) {
        h1->next = mergeTwoLists(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeTwoLists(h1, h2->next);
        return h2;
    }
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to insert node at end
void insertAtEnd(ListNode*& head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

int main() {
    // Example: first sorted list
    ListNode* h1 = NULL;
    insertAtEnd(h1, 1);
    insertAtEnd(h1, 3);
    insertAtEnd(h1, 5);

    // Example: second sorted list
    ListNode* h2 = NULL;
    insertAtEnd(h2, 2);
    insertAtEnd(h2, 4);
    insertAtEnd(h2, 6);

    cout << "List 1: ";
    printList(h1);
    cout << "List 2: ";
    printList(h2);

    // Merge lists
    ListNode* merged = mergeTwoLists(h1, h2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
