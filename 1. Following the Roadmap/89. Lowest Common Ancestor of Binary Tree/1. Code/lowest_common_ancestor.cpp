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

// Build tree from preorder input (-1 means NULL)
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;

    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Recursive LCA function
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If root is one of the nodes
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    // If n1 found in left and n2 found in right
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    // Otherwise return non-NULL child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    int n1, n2;
    cout << "Enter two nodes: ";
    cin >> n1 >> n2;

    Node* ancestor = LCA(root, n1, n2);
    if (ancestor != NULL)
        cout << "Lowest Common Ancestor: " << ancestor->data << endl;
    else
        cout << "One or both nodes not found in tree!" << endl;

    return 0;
}
