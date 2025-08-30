#include <iostream>
#include <queue>
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

// Recursive function to print Kth level
void printKthLevel(Node* root, int k, int currLevel = 1) {
    if (root == NULL) return;

    if (currLevel == k) {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k, currLevel + 1);
    printKthLevel(root->right, k, currLevel + 1);
}

// Iterative BFS approach
void printKthLevelBFS(Node* root, int k) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (level == k) {
                cout << curr->data << " ";
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (level == k) return; // stop after printing kth level
        level++;
    }
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    int k;
    cout << "Enter K: ";
    cin >> k;

    cout << "Kth Level (Recursive): ";
    printKthLevel(root, k);
    cout << endl;

    cout << "Kth Level (BFS Iterative): ";
    printKthLevelBFS(root, k);
    cout << endl;

    return 0;
}
