#include <iostream>
using namespace std;

// Definition of the Node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert node at the end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to swap nodes in pairs
Node* swapPairs(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* first = head;
    Node* second = head->next;
    Node* prev = NULL;

    head = second; // New head after first swap

    while (first != NULL && second != NULL) {
        Node* third = second->next;

        // Swapping
        second->next = first;
        first->next = third;

        if (prev != NULL) {
            prev->next = second;
        }

        // Update pointers for next pair
        prev = first;
        first = third;
        if (first != NULL)
            second = first->next;
    }

    return head;
}

// Driver Code
int main() {
    Node* head = NULL;

    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "Original List:\n";
    printList(head);

    head = swapPairs(head);

    cout << "List After Swapping Pairs:\n";
    printList(head);

    return 0;
}
