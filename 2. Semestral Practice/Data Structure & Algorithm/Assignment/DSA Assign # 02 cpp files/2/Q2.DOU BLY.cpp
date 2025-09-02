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
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
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

    void reverseNnodes(int n) {
        if (!head || n <= 1) {
            return;
        }

        Node* current = head;
        Node* prevNode = NULL;

        for (int i = 0; i < n - 1 && current; i++) {
            prevNode = current;
            current = current->next;
        }

        if (!current) {
            return; // n is greater than or equal to the number of nodes
        }

        Node* nextNode = NULL;
        Node* tailNode = prevNode;

        for (int i = 0; i < n; i++) {
            nextNode = current->next;
            current->next = prevNode;
            current->prev = nextNode;
            prevNode = current;
            current = nextNode;
        }

        if (tailNode) {
            tailNode->next = prevNode;
            prevNode->prev = tailNode;
        } else {
            head = prevNode;
            prevNode->prev = NULL;
        }
    }
};

int main() {
    DoublyLinkedList list;
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

    cout << "Old list: ";
    list.display();

    int n;
    cout << "Enter n: ";
    cin >> n;

    list.reverseNnodes(n);

    cout << "New list: ";
    list.display();

    return 0;
}

