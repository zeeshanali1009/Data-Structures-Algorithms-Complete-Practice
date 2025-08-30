#include <iostream>
#include <vector>
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

// Build Balanced BST from sorted array
Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Inorder traversal (to check BST)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node* root = sortedArrayToBST(arr, 0, arr.size() - 1);

    cout << "Inorder traversal of Balanced BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
