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

// Morris Inorder Traversal
void morrisTraversal(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // If no left child, visit this node and go right
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // Find the inorder predecessor of curr
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            // If right of predecessor is NULL, make thread (temporary link)
            if (pred->right == NULL) {
                pred->right = curr;   // make thread
                curr = curr->left;
            }
            // If thread already exists, break it and visit curr
            else {
                pred->right = NULL;   // remove thread
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
    /*
             1
           /   \
          2     3
         / \   /
        4   5 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Morris Inorder Traversal: ";
    morrisTraversal(root);
    cout << endl;

    return 0;
}
