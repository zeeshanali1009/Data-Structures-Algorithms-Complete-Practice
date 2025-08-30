#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to find LCA in a BST
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;

    // If both p and q are smaller than root, LCA lies in left subtree
    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }
    // If both p and q are greater than root, LCA lies in right subtree
    else if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }
    // Otherwise, this root is the split point → LCA
    else {
        return root;
    }
}

int main() {
    /*
              6
             / \
            2   8
           / \ / \
          0  4 7  9
            / \
           3   5
    */
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    Node* p = root->left;         // Node 2
    Node* q = root->left->right;  // Node 4

    Node* ans = lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "LCA of " << p->data << " and " << q->data
             << " is: " << ans->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
