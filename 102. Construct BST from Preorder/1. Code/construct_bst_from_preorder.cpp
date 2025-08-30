#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Recursive helper
Node* buildBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
    // Base case: if all elements are used or out of range
    if (index >= preorder.size()) return NULL;

    int val = preorder[index];
    if (val < minVal || val > maxVal) return NULL;

    // Construct current node
    Node* root = new Node(val);
    index++; // move to next element

    // Construct left & right subtrees using updated ranges
    root->left = buildBST(preorder, index, minVal, val - 1);
    root->right = buildBST(preorder, index, val + 1, maxVal);

    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return buildBST(preorder, index, INT_MIN, INT_MAX);
}

// Inorder traversal to check correctness (should give sorted order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node* root = bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root); // should be sorted
    cout << endl;

    return 0;
}
