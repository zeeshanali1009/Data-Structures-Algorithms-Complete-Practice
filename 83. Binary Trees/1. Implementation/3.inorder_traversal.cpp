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

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Inorder Traversal: ";
    inorder(root);
    return 0;
}
