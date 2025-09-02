#include <iostream>

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

    // Remove Duplicate Node without using <unordered_set>
    void removeDuplicates() {
        Node* current = head;

        while (current != NULL) {
            Node* runner = current;

            // Iterate through the list to check for duplicates
            while (runner->next != NULL) {
                if (runner->next->data == current->data) {
                    // Duplicate found, remove the node
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                } else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    // Swapping Nodes
    void swapNodes(int x, int y) {
        if (x == y) return;

        Node* prevX = NULL;
        Node* currX = head;
        while (currX != NULL && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        Node* prevY = NULL;
        Node* currY = head;
        while (currY != NULL && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (currX == NULL || currY == NULL) return;

        if (prevX != NULL) {
            prevX->next = currY;
        } else {
            head = currY;
        }

        if (prevY != NULL) {
            prevY->next = currX;
        } else {
            head = currX;
        }

        Node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
    }

    // Sorting Nodes (using Bubble Sort)
    void sortNodes() {
        if (head == NULL || head->next == NULL) return;

        bool swapped;
        Node* last = NULL;
        Node* current;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }

            last = current;

        } while (swapped);
    }

    // Delete Node
    void deleteNode(int value) {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;

        if (prev != NULL) {
            prev->next = current->next;
        } else {
            head = current->next;
        }

        delete current;
    }

    // Insert Node at the end
    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    // Insert nodes
    myList.insertNode(5);
    myList.insertNode(2);
    myList.insertNode(8);
    myList.insertNode(1);
    myList.insertNode(4);

    std::cout << "Original linked list: ";
    myList.display();

    // Remove duplicates
    myList.removeDuplicates();
    std::cout << "Linked list after removing duplicates: ";
    myList.display();

    // Swap nodes 2 and 8
    myList.swapNodes(2, 8);
    std::cout << "Linked list after swapping nodes 2 and 8: ";
    myList.display();

    // Sort nodes
    myList.sortNodes();
    std::cout << "Linked list after sorting: ";
    myList.display();

    // Delete node with value 4
    myList.deleteNode(4);
    std::cout << "Linked list after deleting node with value 4: ";
    myList.display();

    // Insert node with value 7
    myList.insertNode(7);
    std::cout << "Linked list after inserting node with value 7: ";
    myList.display();

    return 0;
}
