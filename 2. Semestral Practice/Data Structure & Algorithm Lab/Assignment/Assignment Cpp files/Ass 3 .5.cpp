#include <iostream>
#include <queue>
using namespace std;

class BST {
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST* Insert(BST*, int);
    void Inorder(BST*);
    int findKthSmallest(BST*, int, int&);
};

BST ::BST(){
    data=0;
    left=NULL;
    right=NULL;
}

BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
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

void BST ::Inorder(BST* root)
{
    if (root==NULL) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int BST::findKthSmallest(BST* root, int k, int& count) {
    if (root == NULL) {
        return -1;
    }

    int leftResult = findKthSmallest(root->left, k, count);

    if (leftResult != -1) {
        return leftResult;
    }

    count++;

    if (count == k) {
        return root->data;
    }

    return findKthSmallest(root->right, k, count);
}

int main()
{
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

    int k = 3;

    int count = 0;
    int kthSmallest = b.findKthSmallest(root, k, count);

    if (kthSmallest != -1) {
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    } else {
        cout << "Invalid value of K." << endl;
    }

    return 0;
}

