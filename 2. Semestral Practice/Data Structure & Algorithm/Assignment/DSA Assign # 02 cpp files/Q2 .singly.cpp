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
    LinkedList() : head(NULL) {}
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
};
int main() {
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(2);
    list1.insert(1);

    cout << "Linked List 1: ";
    list1.display();

    Node* middle1 = list1.middleNode(list1.head);
    if (middle1) {
        cout << "Output: Odd case" << endl;
        cout << middle1->data << " is the middle node" << endl;
    } else {
        cout << "Output: Empty list" << endl;
    }

    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(4);
    list2.insert(3);
    list2.insert(1);
    list2.insert(8);

    cout << "Linked List 2: ";
    list2.display();

    Node* middle2 = list2.middleNode(list2.head);
    if (middle2) {
        cout << "Output: Even case" << endl;
        cout << middle2->data << endl;
    } else {
        cout << "Output: Empty list" << endl;
    }

    return 0;
}

