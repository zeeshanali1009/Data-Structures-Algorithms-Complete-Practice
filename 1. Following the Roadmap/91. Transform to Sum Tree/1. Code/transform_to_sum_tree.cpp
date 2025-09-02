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

// Transform to Sum Tree
int transformToSumTree(Node* root) {
    if (root == NULL) return 0;

    // Recursively convert left and right subtrees
    int leftSum = transformToSumTree(root->left);
    int rightSum = transformToSumTree(root->right);

    // Store current node's old value
    int oldVal = root->data;

    // Replace node's value with leftSum + rightSum
    root->data = leftSum + rightSum;

    // Return sum of values under this subtree (including old value)
    return root->data + oldVal;
}

// Inorder Traversal (for checking)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
             10
           /    \
          -2     6
         /  \   / \
        8   -4 7   5
    */

    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    cout << "Inorder before Sum Tree: ";
    inorder(root);
    cout << endl;

    transformToSumTree(root);

    cout << "Inorder after Sum Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
