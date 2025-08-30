#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to flatten binary tree to linked list
void flatten(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    // If left subtree exists, flatten it
    if (root->left != NULL) {
        flatten(root->left);

        // Store the right subtree
        Node* tempRight = root->right;

        // Move left subtree to right
        root->right = root->left;
        root->left = NULL;

        // Find the rightmost node of new right subtree
        Node* t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }

        // Attach the old right subtree
        t->right = tempRight;
    }

    // Flatten the right subtree
    flatten(root->right);
}

// Helper function to print flattened tree
void printList(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    /*
             1
           /   \
          2     5
         / \     \
        3   4     6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);

    cout << "Flattened tree to linked list: ";
    printList(root);

    return 0;
}
