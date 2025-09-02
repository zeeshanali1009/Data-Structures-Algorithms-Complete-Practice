#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(NULL) {}

    void insert(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            head->next = head; // Make it circular
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = head;
        }
    }

    void display() {
        Node* current = head;
        do {
            cout << current->data;
            if (current->next != head) {
                cout << " -> ";
            }
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    bool isCircularList() {
        if (!head) {
            return false;
        }

        Node* current = head;
        while (current->next != head) {
            if (current->next == NULL) {
                return false; // If the next pointer is nullptr, it's not circular.
            }
            current = current->next;
        }
        return true; // If the loop completes, it's circular.
    }

    void makeCircularList() {
        if (!isCircularList()) {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = head; // Make it circular
        }
    }

    void addNodeToCircularList(int data) {
        if (isCircularList()) {
            Node* new_node = new Node(data);
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = new_node;
            new_node->next = head;
        }
    }
};

int main() {
    CircularLinkedList list;
    list.insert(1);
    list.insert(5);
    list.insert(8);
    list.insert(10);
    list.insert(2);
    list.insert(4);
    list.insert(8);
    list.insert(9);
    list.insert(11);
    list.insert(34);

    cout << "List: ";
    list.display();

    if (list.isCircularList()) {
        cout << "Output: List is circular" << endl;
    } else {
        cout << "Output: List is singly linked list" << endl;
    }

    int newData;
    cout << "Enter new node: ";
    cin >> newData;

    list.addNodeToCircularList(newData);

    cout << "List with the new node: ";
    list.display();

    return 0;
}

