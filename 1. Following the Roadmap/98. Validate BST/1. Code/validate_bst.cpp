#include <iostream>
#include <climits>
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

// Validate BST using recursion with range check
bool isValidBST(Node* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}

int main() {
    // ✅ Example BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (isValidBST(root, LLONG_MIN, LLONG_MAX))
        cout << "Tree is a VALID BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    // ❌ Example non-BST
    Node* badRoot = new Node(10);
    badRoot->left = new Node(5);
    badRoot->right = new Node(8); // violates BST rule

    if (isValidBST(badRoot, LLONG_MIN, LLONG_MAX))
        cout << "Tree is a VALID BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    return 0;
}
