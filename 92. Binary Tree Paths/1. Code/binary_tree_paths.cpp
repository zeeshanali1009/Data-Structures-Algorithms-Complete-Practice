#include <iostream>
#include <vector>
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

// Recursive function to print all root-to-leaf paths
void printPaths(Node* root, vector<int>& path) {
    if (root == NULL) return;

    // Add current node to the path
    path.push_back(root->data);

    // If leaf node -> print path
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << "->";
        }
        cout << endl;
    } else {
        // Recurse left and right
        printPaths(root->left, path);
        printPaths(root->right, path);
    }

    // Backtrack (remove current node before returning to parent)
    path.pop_back();
}

int main() {
    /*
             1
           /   \
          2     3
           \
            5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    vector<int> path;
    cout << "Root-to-leaf paths:\n";
    printPaths(root, path);

    return 0;
}
