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

// Sum of all nodes using recursion
int sumNodes(Node* root) {
    if (root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Sum of all Nodes: " << sumNodes(root) << endl;
    return 0;
}
