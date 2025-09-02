#include <iostream>
#include <queue>
using namespace std;

class BST {
	public:
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Inorder(BST*);
	void preorder(BST*);
	void postorder(BST*);
	void DFS_InOrder(BST*);
	void DFS_PreOrder(BST*);
	void DFS_PostOrder(BST*);
	void BFS_LevelOrder(BST*);
	BST* inorderSuccessor(BST*, BST*);
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
	cout << root->data << endl;
	Inorder(root->right);
}
BST* BST ::inorderSuccessor(BST* root, BST* node) {
	if (node->right != NULL) {

		BST* successor = node->right;
		while (successor->left != NULL) {
			successor = successor->left;
		}
		return successor;
	}
	BST* successor = NULL;
	while (root != NULL) {
		if (node->data < root->data) {
			successor = root;
			root = root->left;
		} else if (node->data > root->data) {
			root = root->right;
		} else {
			break;
		}
	}

	return successor;
}




// Driver code
int main()
{
	BST b, *root = NULL;

    root = b.Insert(root, 8);
    // Insert elements...
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
	// Assuming you have a node for which you want to find the inorder successor
	int nodeValue = 6;
	BST* nodeToFind = root;
	while (nodeToFind != NULL && nodeToFind->data != nodeValue) {
		if (nodeValue < nodeToFind->data) {
			nodeToFind = nodeToFind->left;
		} else {
			nodeToFind = nodeToFind->right;
		}
	}

	if (nodeToFind != NULL) {
		BST* successor = b.inorderSuccessor(root, nodeToFind);
		if (successor != NULL) {
			cout << "Inorder successor of " << nodeValue << " is: " << successor->data << std::endl;
		} else {
			cout << "No inorder successor found for " << nodeValue << std::endl;
		}
	} else {
		cout << "Node with value " << nodeValue << " not found in the BST." << std::endl;
	}

	return 0;
}

