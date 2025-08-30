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

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printLevelByLevel(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Level by Level Traversal:\n";
    printLevelByLevel(root);
    return 0;
}
