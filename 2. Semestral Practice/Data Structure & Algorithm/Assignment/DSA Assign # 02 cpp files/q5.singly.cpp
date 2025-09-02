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
    void removeDuplicateNodes() {
        Node* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
};
int main() {
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(3);
    list1.insert(8);
    cout << "Original Linked List 1: ";
    list1.display();
    list1.removeDuplicateNodes();
    cout << "Modified Linked List 1: ";
    list1.display();
    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(3);
    list2.insert(8);
    list2.insert(9);
    list2.insert(9);
    list2.insert(12);
    cout << "Original Linked List 2: ";
    list2.display();
    list2.removeDuplicateNodes();
    cout << "Modified Linked List 2: ";
    list2.display();
    LinkedList list3;
    list3.insert(1);
    list3.insert(2);
    list3.insert(4);
    list3.insert(8);
    list3.insert(5);
    cout << "Original Linked List 3: ";
    list3.display();
    list3.removeDuplicateNodes();
    cout << "Modified Linked List 3: ";
    list3.display();
    return 0;
}

