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
        left = right = NULL;
    }
};

// Step 1: Inorder traversal → sorted array
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Step 2: Merge two sorted arrays
vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> temp;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) temp.push_back(arr1[i++]);
        else temp.push_back(arr2[j++]);
    }

    // Remaining elements
    while (i < arr1.size()) temp.push_back(arr1[i++]);
    while (j < arr2.size()) temp.push_back(arr2[j++]);

    return temp;
}

// Step 3: Build BST from sorted array
Node* buildBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);

    return root;
}

// Step 4: Merge BSTs using pseudocode logic
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> arr1, arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> merged = mergeArrays(arr1, arr2);

    return buildBST(merged, 0, merged.size() - 1);
}

// Utility: Print inorder of BST
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // First BST
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // Second BST
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Node* merged = mergeBSTs(root1, root2);

    cout << "Inorder of merged BST: ";
    printInorder(merged);
    cout << endl;

    return 0;
}
