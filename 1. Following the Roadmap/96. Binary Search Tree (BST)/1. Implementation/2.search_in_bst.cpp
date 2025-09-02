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

// Search in BST
bool searchBST(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    if (key < root->data) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {5, 1, 3, 4, 2, 7};

    for (int i = 0; i < 6; i++) {
        root = insertBST(root, arr[i]);
    }

    int key = 4;
    if (searchBST(root, key)) {
        cout << key << " found in BST" << endl;
    } else {
        cout << key << " not found in BST" << endl;
    }

    return 0;
}
