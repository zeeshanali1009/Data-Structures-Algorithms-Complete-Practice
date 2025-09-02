#include <iostream>
using namespace std;

class BST {
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST* Insert(BST*, int);
    bool searchRecursive(BST*, int);
    bool searchIterative(BST*, int);
};

BST::BST(){
    data=0;
    left=NULL;
    right=NULL;
}

BST::BST(int value){
    data = value;
    left = right = NULL;
}

BST* BST::Insert(BST* root, int value){
    if (root==NULL) {
        return new BST(value);
    }

    if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    else if (value < root->data){
        root->left = Insert(root->left, value);
    }

    return root;
}

bool BST::searchRecursive(BST* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}

bool BST::searchIterative(BST* root, int key) {
    while (root != NULL) {
        if (root->data == key) {
            return true;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}

int main() {
    BST b, *root = NULL;

    root = b.Insert(root, 8);
    b.Insert(root, 3);
    b.Insert(root, 10);
    b.Insert(root, 1);
    b.Insert(root, 6);
    b.Insert(root, 14);
    b.Insert(root, 4);
    b.Insert(root, 7);
    b.Insert(root, 13);
    b.Insert(root, 15);
    b.Insert(root, 2);
    b.Insert(root, 5);

    int keyToSearch = 6;

    if (b.searchRecursive(root, keyToSearch)) {
        cout << "Key " << keyToSearch << " found using recursive search." << endl;
    } else {
        cout << "Key " << keyToSearch << " not found using recursive search." << endl;
    }

    if (b.searchIterative(root, keyToSearch)) {
        cout << "Key " << keyToSearch << " found using iterative search." << endl;
    } else {
        cout << "Key " << keyToSearch << " not found using iterative search." << endl;
    }

    return 0;
}

