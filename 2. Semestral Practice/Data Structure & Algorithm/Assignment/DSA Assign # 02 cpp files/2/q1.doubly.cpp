#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(NULL) {}

    void insert(int data) {
        Node* new_node = new Node(data);

        if (!head) {
            head = new_node;
        } else if (data <= head->data) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        } else {
            Node* current = head;

            while (current->next && current->next->data < data) {
                current = current->next;
            }

            new_node->next = current->next;
            new_node->prev = current;

            if (current->next) {
                current->next->prev = new_node;
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
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(5);
    list.insert(8);
    list.insert(10);

    cout << "Old list: ";
    list.display();

    int newData;
    cout << "Enter the new value to place: ";
    cin >> newData;

    list.insert(newData);

    cout << "New list: ";
    list.display();

    return 0;
}

