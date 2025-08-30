#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next; // next right pointer

    Node(int val) {
        data = val;
        left = right = next = NULL;
    }
};

// Recursive helper
void connect(Node* root) {
    if (!root || !root->left || !root->right) return;

    // Connect left -> right
    root->left->next = root->right;

    // Connect right -> next left (if exists)
    if (root->next) {
        root->right->next = root->next->left;
    }

    // Recurse on left and right subtrees
    connect(root->left);
    connect(root->right);
}

// Print tree level using next pointers
void printLevels(Node* root) {
    while (root) {
        Node* curr = root;
        while (curr) {
            cout << curr->data << " -> ";
            if (curr->next)
                cout << curr->next->data << "   ";
            else
                cout << "NULL   ";
            curr = curr->next;
        }
        cout << endl;
        root = root->left;
    }
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connect(root);

    cout << "Levels with Next Right Pointers: " << endl;
    printLevels(root);

    return 0;
}
