#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* DeleteConsectiveSum(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    while (current) {
        int sum = 0;
        Node* temp = current;
        while (temp) {
            sum += temp->data;
            if (sum == 0) {
                while (current != temp->next) {
                    Node* toDelete = current;
                    current = current->next;
                    delete toDelete;
                }
                if (!prev) {
                    head = current;
                } else {
                    prev->next = current;
                }
                break;
            }
            temp = temp->next;
        }
        prev = current;
        current = current->next;
    }
    return head;
}
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    Node* head = new Node{7, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{-3, NULL};
    head->next->next->next->next = new Node{9, NULL};
    cout << "Original Linked List: ";
    display(head);
    head = DeleteConsectiveSum(head);
    cout << "Modified Linked List: ";
    display(head);
    return 0;
}

