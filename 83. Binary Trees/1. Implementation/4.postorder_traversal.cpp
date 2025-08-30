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

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Postorder Traversal: ";
    postorder(root);
    return 0;
}
