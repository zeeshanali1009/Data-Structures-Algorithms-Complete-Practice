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

void recoverBST(Node* root) {
    Node* first = NULL;
    Node* second = NULL;
    Node* prev = NULL;
    Node* curr = root;

    while (curr) {
        if (!curr->left) {
            // Check violation
            if (prev && curr->data < prev->data) {
                if (!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        } else {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) pred = pred->right;

            if (!pred->right) {
                pred->right = curr; // Create thread
                curr = curr->left;
            } else {
                pred->right = NULL; // Remove thread
                if (prev && curr->data < prev->data) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }

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
