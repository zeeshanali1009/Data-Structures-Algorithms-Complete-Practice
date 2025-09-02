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

    void evenOdd() {
        if (!head || !head->next) {
            return;
        }

        LinkedList evenList;  // Temporary list for even values
        LinkedList oddList;   // Temporary list for odd values

        Node* current = head;

        while (current) {
            if (current->data % 2 == 0) {
                evenList.insert(current->data);
            } else {
                oddList.insert(current->data);
            }
            current = current->next;
        }

        head = evenList.head;  // Set the head of the original list to the head of the even list

        Node* evenCurrent = evenList.head;
        while (evenCurrent->next) {
            evenCurrent = evenCurrent->next;
        }

        evenCurrent->next = oddList.head;  // Connect the last even node to the first odd node
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(0);

    cout << "Original Linked List: ";
    list.display();

    list.evenOdd();

    cout << "Modified Linked List: ";
    list.display();

    return 0;
}

