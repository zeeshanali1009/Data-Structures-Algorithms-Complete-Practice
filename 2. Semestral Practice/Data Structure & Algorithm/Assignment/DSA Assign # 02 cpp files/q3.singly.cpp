#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};
class LinkedList {
public:
    Node* head;
    LinkedList() : head( NULL) {}
    void insert(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
    Node* middleNode(Node* head) {
        if (!head) {
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void makeMiddleHead() {
        Node* middle = middleNode(head);
        if (middle) {
            Node* newHead = middle->next;
            middle->next = NULL;
            newHead = reverseList(newHead);

            middle->next = head;
            head = newHead;
        }
    }
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }
};
int main() {
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(2);
    list1.insert(1);
    cout << "Original Linked List 1: ";
    list1.display();
    list1.makeMiddleHead();
    cout << "Modified Linked List 1: ";
    list1.display();
    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(4);
    list2.insert(3);
    list2.insert(1);
    list2.insert(8);
    cout << "Original Linked List 2: ";
    list2.display();
    list2.makeMiddleHead();
    cout << "Modified Linked List 2: ";
    list2.display();
    return 0;
}

