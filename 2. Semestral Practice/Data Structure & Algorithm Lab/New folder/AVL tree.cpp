#include <iostream>
using namespace std;

class AVL {
    int data;
    AVL *left, *right;
    int height;

public:
    // Default constructor.
    AVL();
    // Parameterized constructor.
    AVL(int);
    // Insert function.
    AVL* Insert(AVL*, int);
    // Delete function.
    AVL* Delete(AVL*, int);
    // Inorder, Preorder, Postorder traversal functions.
    void Inorder(AVL*);
    void preorder(AVL*);
    void postorder(AVL*);
    // Get height of the node.
    int getHeight(AVL* node);
    // Get balance factor of the node.
    int getBalance(AVL* node);
    // Rotate subtree rooted with y.
    AVL* rightRotate(AVL* y);
    AVL* leftRotate(AVL* x);
    // Get the node with the minimum value.
    AVL* minValueNode(AVL* node);
};

// Default Constructor definition.
AVL::AVL() {
    data = 0;
    left = right = NULL;
    height = 1;
}

// Parameterized Constructor definition.
AVL::AVL(int value) {
    data = value;
    left = right = NULL;
    height = 1;
}

// Insert function definition.
AVL* AVL::Insert(AVL* root, int value) {
    if (root == NULL) {
        // Insert the first node, if root is NULL.
        return new AVL(value);
    }

    // Insert data.
    if (value < root->data) {
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    } else if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }

    // Update height of the current node.
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor.
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the unchanged node pointer.
    return root;
}

// Get height of the node.
int AVL::getHeight(AVL* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Get balance factor of the node.
int AVL::getBalance(AVL* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Rotate subtree rooted with y.
AVL* AVL::rightRotate(AVL* y) {
    AVL* x = y->left;
    AVL* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Return new root
    return x;
}

AVL* AVL::leftRotate(AVL* x) {
    AVL* y = x->right;
    AVL* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    // Return new root
    return y;
}

// Get the node with the minimum value.
AVL* AVL::minValueNode(AVL* node) {
    AVL* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Inorder traversal function.
// This gives data in sorted order.
void AVL::Inorder(AVL* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);  // left node
    cout << root->data << endl;  // root node
    Inorder(root->right);  // right node
}

// Preorder traversal function.
void AVL::preorder(AVL* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << endl; // root
    preorder(root->left); // left
    preorder(root->right);// right
}

// Postorder traversal function.
void AVL::postorder(AVL* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);  // left node
    postorder(root->right);   // right node
    cout << root->data << endl;  // root node
}

// Driver code
int main() {
    AVL avl, *root = NULL;
    root = avl.Insert(root, 15);
    // Insert elements...
    root = avl.Insert(root, 10);
    root = avl.Insert(root, 20);
    root = avl.Insert(root, 8);
    root = avl.Insert(root, 12);
    root = avl.Insert(root, 17);
    root = avl.Insert(root, 25);

    // Traversals
    cout << "Inorder traversal" << endl;
    avl.Inorder(root);
    cout << "Preorder traversal" << endl;
    avl.preorder(root);
    cout << "Postorder traversal" << endl;
    avl.postorder(root);

    return 0;
}

