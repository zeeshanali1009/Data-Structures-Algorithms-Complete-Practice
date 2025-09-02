#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void SortInBothOrder(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* slowPtr = *head;
    Node* fastPtr = (*head)->next;

    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    Node* firstHalf = *head;
    Node* secondHalf = slowPtr->next;
    slowPtr->next = NULL;

    SortInBothOrder(&firstHalf);
    SortInBothOrder(&secondHalf);

    Node* result = NULL;
    while (firstHalf != NULL && secondHalf != NULL) {
        if (firstHalf->data < secondHalf->data) {
            Node* temp = firstHalf->next;
            firstHalf->next = result;
            result = firstHalf;
            firstHalf = temp;
        } else {
            Node* temp = secondHalf->next;
            secondHalf->next = result;
            result = secondHalf;
            secondHalf = temp;
        }
    }

    while (firstHalf != NULL) {
        Node* temp = firstHalf->next;
        firstHalf->next = result;
        result = firstHalf;
        firstHalf = temp;
    }

    while (secondHalf != NULL) {
        Node* temp = secondHalf->next;
        secondHalf->next = result;
        result = secondHalf;
        secondHalf = temp;
    }

    *head = result;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{7, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{-3, NULL};
    head->next->next->next->next = new Node{9, NULL};
    
    Node* current = head;
    printList(head);

    SortInBothOrder(&head);
    printList(head);

    return 0;
}

