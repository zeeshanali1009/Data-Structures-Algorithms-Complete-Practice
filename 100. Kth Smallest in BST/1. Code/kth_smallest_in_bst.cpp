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

int preorder = 0;  // counter for inorder traversal

int kthSmallest(Node* root, int k) {
    if (root == NULL) return -1;

    // 1. Search in left subtree
    if (root->left) {
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1) return leftAns;
    }

    // 2. Visit root node
    if (preorder + 1 == k) {
        return root->data;
    }
    preorder++;

    // 3. Search in right subtree
    if (root->right) {
        int rightAns = kthSmallest(root->right, k);
        if (rightAns != -1) return rightAns;
    }

    return -1;
}

int main() {
    // Example BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    int k = 3;
    preorder = 0; // reset before call
    cout << k << "rd smallest element in BST: "
         << kthSmallest(root, k) << endl;

    return 0;
}
