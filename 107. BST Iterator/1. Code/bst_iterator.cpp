#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    // Push all left children into stack
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Return true if there is a next smallest
    bool hasNext() {
        return !st.empty();
    }

    // Return the next smallest element
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        int val = curr->val;

        // If right child exists, push all its left children
        if (curr->right) {
            pushLeft(curr->right);
        }

        return val;
    }
};

int main() {
    /*
           7
          / \
         3   15
            /  \
           9    20
    */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    cout << "Inorder traversal using BST Iterator: " << endl;
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}
