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
    void sortList() {
        if (!head || !head->next) {
            return;
        }
        Node* current = head;
        while (current) {
            Node* minNode = current;
            Node* temp = current;
            while (temp) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
            current = current->next;
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
    list1.sortList();
    cout << "Sorted Linked List 1: ";
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
    list2.sortList();
    cout << "Sorted Linked List 2: ";
    list2.display();
    return 0;
}

