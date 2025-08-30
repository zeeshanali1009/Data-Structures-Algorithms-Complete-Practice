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

// Check if two trees are identical
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {
    cout << "Enter Tree 1 in preorder (-1 for NULL): ";
    Node* root1 = buildTree();

    cout << "Enter Tree 2 in preorder (-1 for NULL): ";
    Node* root2 = buildTree();

    if (isIdentical(root1, root2))
        cout << "Both trees are identical." << endl;
    else
        cout << "Trees are NOT identical." << endl;

    return 0;
}
