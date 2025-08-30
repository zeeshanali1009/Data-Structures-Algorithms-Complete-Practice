#include <iostream>
#include <queue>
#include <algorithm>
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

// Function to calculate maximum width of Binary Tree
int maxWidth(Node* root) {
    if (!root) return 0;

    int ans = 0;
    queue<pair<Node*, long long>> q;  // store node + index
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        long long minIndex = q.front().second; // minimum index at this level
        long long first, last;

        for (int i = 0; i < size; i++) {
            long long currIndex = q.front().second - minIndex; // normalized index
            Node* node = q.front().first;
            q.pop();

            if (i == 0) first = currIndex;      // first index at this level
            if (i == size - 1) last = currIndex; // last index at this level

            if (node->left) q.push({node->left, currIndex * 2 + 1});
            if (node->right) q.push({node->right, currIndex * 2 + 2});
        }
        ans = max(ans, (int)(last - first + 1));
    }
    return ans;
}

int main() {
    /*
             1
           /   \
          2     3
         / \     \
        4   5     8
                 / \
                6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Maximum Width of Binary Tree = " << maxWidth(root) << endl;

    return 0;
}
