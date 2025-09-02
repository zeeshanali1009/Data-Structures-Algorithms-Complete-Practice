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
    void swapNodes() {
        Node* current = head;

        while (current && current->next) {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            current = current->next->next;
        }
    }
};

int main() {
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(2);
    list1.insert(0);

    cout << "Original Linked List 1: ";
    list1.display();

    list1.swapNodes();

    cout << "Modified Linked List 1: ";
    list1.display();

    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(4);
    list2.insert(8);
    list2.insert(5);
    list2.insert(6);

    cout << "Original Linked List 2: ";
    list2.display();

    list2.swapNodes();

    cout << "Modified Linked List 2: ";
    list2.display();

    return 0;
}

