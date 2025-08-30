#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Struct to hold information for each subtree
struct Info {
    int minVal, maxVal, size;
    bool isBST;
    Info(int mn, int mx, int sz, bool bst) {
        minVal = mn;
        maxVal = mx;
        size = sz;
        isBST = bst;
    }
};

// Helper function
Info helper(Node* root, int &ans) {
    // Base case
    if (!root) 
        return Info(INT_MAX, INT_MIN, 0, true);

    // Leaf node
    if (!root->left && !root->right) {
        ans = max(ans, 1);
        return Info(root->data, root->data, 1, true);
    }

    Info leftInfo  = helper(root->left, ans);
    Info rightInfo = helper(root->right, ans);

    // Check if subtree rooted at current node is BST
    if (leftInfo.isBST && rightInfo.isBST &&
        root->data > leftInfo.maxVal &&
        root->data < rightInfo.minVal) {

        int currSize = leftInfo.size + rightInfo.size + 1;
        ans = max(ans, currSize);
        return Info(min(root->data, leftInfo.minVal),
                    max(root->data, rightInfo.maxVal),
                    currSize, true);
    }

    // If not BST, return false
    return Info(INT_MIN, INT_MAX, max(leftInfo.size, rightInfo.size), false);
}

// Main function
int largestBST(Node* root) {
    int ans = 0;
    helper(root, ans);
    return ans;
}

// Driver Code
int main() {
    /* Example Tree:
             50
           /    \
         30      60
        /  \    /  \
      5    20  45   70
                   /   \
                 65     80
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    cout << "Size of Largest BST is: " << largestBST(root) << endl;

    return 0;
}
