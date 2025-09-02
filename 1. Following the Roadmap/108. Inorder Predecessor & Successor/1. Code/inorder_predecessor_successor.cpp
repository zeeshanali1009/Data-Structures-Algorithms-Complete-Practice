#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility: rightmost node in a subtree
Node* rightMost(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// Utility: leftmost node in a subtree
Node* leftMost(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Function to find predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre = suc = NULL;
    Node* curr = root;

    while (curr) {
        if (key == curr->data) {
            // Predecessor = rightmost in left subtree
            if (curr->left) pre = rightMost(curr->left);
            // Successor = leftmost in right subtree
            if (curr->right) suc = leftMost(curr->right);
            break;
        }
        else if (key < curr->data) {
            suc = curr;             // possible successor
            curr = curr->left;
        }
        else {
            pre = curr;             // possible predecessor
            curr = curr->right;
        }
    }
}

// Driver Code
int main() {
    /*
              8
            /   \
           4     12
          / \   /  \
         2   6 10  14
    */

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key = 10;
    Node* pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, key);

    if (pre) cout << "Predecessor of " << key << " is " << pre->data << endl;
    else cout << "No Predecessor\n";

    if (suc) cout << "Successor of " << key << " is " << suc->data << endl;
    else cout << "No Successor\n";

    return 0;
}
