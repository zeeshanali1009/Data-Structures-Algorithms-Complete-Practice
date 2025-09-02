#include <iostream>
#include <map>
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

// Function to print top view
void topView(Node* root) {
    if (!root) return;

    // map<hd, node_value>
    map<int, int> mp;
    // queue<node, hd>
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* curr = p.first;
        int hd = p.second;

        // Only insert if hd not seen before
        if (mp.find(hd) == mp.end()) {
            mp[hd] = curr->data;
        }

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    // Print top view in order of horizontal distance
    for (auto it : mp) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";
    Node* root = buildTree();

    cout << "Top View of Tree: ";
    topView(root);

    return 0;
}
