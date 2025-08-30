#include <iostream>
#include <algorithm>
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

// Helper function: returns height and updates diameter
int diameterHelper(Node* root, int &diameter) {
    if (root == NULL) return 0;

    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);

    // diameter at current node = leftHeight + rightHeight
    diameter = max(diameter, leftHeight + rightHeight);

    // return height of current node
    return max(leftHeight, rightHeight) + 1;
}

// Main function to calculate diameter
int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    diameterHelper(root, diameter);
    return diameter;
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Diameter of the tree = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
