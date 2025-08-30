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

// Insert node in BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {5, 1, 3, 4, 2, 7};

    for (int i = 0; i < 6; i++) {
        root = insertBST(root, arr[i]);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
