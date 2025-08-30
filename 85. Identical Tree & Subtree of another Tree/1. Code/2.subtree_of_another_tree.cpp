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

// Check if subtree2 is a subtree of main tree1
bool isSubtree(Node* root1, Node* root2) {
    if (root2 == NULL) return true;  // empty tree is always a subtree
    if (root1 == NULL) return false;

    if (isIdentical(root1, root2)) return true;

    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main() {
    cout << "Enter Main Tree in preorder (-1 for NULL): ";
    Node* root1 = buildTree();

    cout << "Enter Subtree in preorder (-1 for NULL): ";
    Node* root2 = buildTree();

    if (isSubtree(root1, root2))
        cout << "The second tree IS a subtree of the first tree." << endl;
    else
        cout << "The second tree is NOT a subtree of the first tree." << endl;

    return 0;
}
