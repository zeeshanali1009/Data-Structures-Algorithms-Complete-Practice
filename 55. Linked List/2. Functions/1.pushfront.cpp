#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* head = nullptr;

void pushFront(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    pushFront(10);
    pushFront(20);
    pushFront(30);
    printList(); // 30 -> 20 -> 10 -> NULL
}
