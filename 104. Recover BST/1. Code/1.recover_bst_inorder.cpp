#include <iostream>
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

Node* first = NULL;
Node* second = NULL;
Node* prevNode = NULL;

// Recursive inorder traversal
void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);

    // Check for violation
    if (prevNode && root->data < prevNode->data) {
        if (!first) first = prevNode;   // First wrong node
        second = root;                  // Second wrong node
    }
    prevNode = root;

    inorder(root->right);
}

void recoverBST(Node* root) {
    first = second = prevNode = NULL;
    inorder(root);

    if (first && second) swap(first->data, second->data);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);   // Wrong
    root->left->left = new Node(2);
    root->left->right = new Node(20);  // Wrong

    cout << "Before Recovery: ";
    printInorder(root);
    cout << endl;

    recoverBST(root);

    cout << "After Recovery: ";
    printInorder(root);
    cout << endl;
}
