#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Class for Linked List
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
};
int main() {
    LinkedList list;
}