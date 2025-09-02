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
    bool isPalindrome() {
        if (!head || !head->next) {
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* prev = NULL;
        Node* current = slow;
        while (current) {
            Node* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        Node* firstHalf = head;
        Node* secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    cout << "Linked List: ";
    list.display();
    if (list.isPalindrome()) {
        cout << "Output: it's Palindrome" << endl;
    } else {
        cout << "Output: it's not a Palindrome" << endl;
    }
    return 0;
}

