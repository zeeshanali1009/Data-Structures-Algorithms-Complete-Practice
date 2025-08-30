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

// Count nodes using recursion
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Total Nodes in Tree: " << countNodes(root) << endl;
    return 0;
}
