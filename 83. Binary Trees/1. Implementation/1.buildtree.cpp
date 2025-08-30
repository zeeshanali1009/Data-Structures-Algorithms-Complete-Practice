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

// Build tree from preorder input (-1 for NULL)
Node* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();
    cout << "Tree built successfully!" << endl;
    return 0;
}
