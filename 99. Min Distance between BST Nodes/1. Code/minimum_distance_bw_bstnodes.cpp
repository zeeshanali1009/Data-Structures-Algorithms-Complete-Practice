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

// Recursive function for inorder traversal & min diff
void inorder(Node* root, int &prev, int &minDiff) {
    if (root == NULL) return;

    // Left subtree
    inorder(root->left, prev, minDiff);

    // Process current node
    if (prev != -1) {
        minDiff = min(minDiff, root->data - prev);
    }
    prev = root->data; // update prev

    // Right subtree
    inorder(root->right, prev, minDiff);
}

// Main function to return minimum difference
int getMinimumDifference(Node* root) {
    int prev = -1;
    int minDiff = INT_MAX;
    inorder(root, prev, minDiff);
    return minDiff;
}

int main() {
    // Example BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Minimum distance between BST nodes: " 
         << getMinimumDifference(root) << endl;

    return 0;
}
