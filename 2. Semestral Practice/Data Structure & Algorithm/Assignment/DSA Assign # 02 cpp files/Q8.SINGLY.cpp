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

    void reverseList() {
        if (!head || !head->next) {
            return;
        }

        Node* prev = NULL;
        Node* current = head;
        Node* next_node = NULL;

        while (current) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        head = prev; // Set the head to the new first node
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(9);
    list.insert(0);

    cout << "Original Linked List: ";
    list.display();

    list.reverseList();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}

