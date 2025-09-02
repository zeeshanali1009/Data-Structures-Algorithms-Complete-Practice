#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

	// Inorder traversal.
	void preorder(BST*);   //root left right 
	void Inorder(BST*);    //left root right 
	void postorder(BST*); //left right root
};

// Default Constructor definition.
BST ::BST(){   //:: scop resulation operator 
	data=0;
	left=NULL;
	right=NULL;
}
// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}
// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (root==NULL) {
		//BST* newBSTNode=new BST(value);
//		newBStNode->data=data;
//		newBStNode->left=NULL;
//		newBStNode->right=NULL;
//		return newBSTNode;
		
		// Insert the first node, if root is NULL.
		return new BST(value);
	}

	// Insert data.
	if (value > root->data) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value);
	}
	else if (value <= root->data){
		// Insert left node data, if the 'value'
		// to be inserted is smaller than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
	if (root==NULL) {
		return;
	}
	Inorder(root->left);  //left node
	cout << root->data << endl;  //root node
	Inorder(root->right);  //right node
}
void BST ::preorder(BST* root)
{
	if (root==NULL) {
		return;
	}
	cout << root->data << endl; //root 
	preorder(root->left); //left 
	preorder(root->right);// right 
}
void BST ::postorder(BST* root)
{
	if (root==NULL) {
		return;
	}
	postorder(root->left);  //left node
	postorder(root->right);   //right node
	cout << root->data << endl;  //root node
}

// Driver code
int main()
{
	//        15   root node
	//    l  /    \ r
	//     10     20
	//   l / \r  l /  \r
	//    08   12  17   25
	BST b, *root = NULL; //root is empty 
	root = b.Insert(root, 15);
	b.Insert(root, 10);
	b.Insert(root, 20);
	b.Insert(root, 8);
	b.Insert(root, 12);
	b.Insert(root, 17);
	b.Insert(root, 25);
	cout<<"inorder treversing"<<endl;
	b.Inorder(root);
	cout<<"preorder treversing"<<endl;
	b.preorder(root);
	cout<<"postorder treversing"<<endl;
	b.postorder(root);
	return 0;
}

