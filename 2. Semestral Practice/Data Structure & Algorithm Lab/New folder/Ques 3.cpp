/*Define a function RemoveDuplicateNode(Node *head) which remove the
duplicate node ( repeating ) from
the sorted link list and display the resultant list. Sample:
1 -> 2 -> 3 -> 3 -> 8
Output: 1 -> 2 -> 3 -> 8*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};
void RemoveDuplicateNode(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            
            current = current->next;
        }
    }
}
void DisplayList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(8);
    cout << "Original List: ";
    DisplayList(head);
    RemoveDuplicateNode(head);
    cout << "List after removing duplicates: ";
    DisplayList(head);
    return 0;
}
