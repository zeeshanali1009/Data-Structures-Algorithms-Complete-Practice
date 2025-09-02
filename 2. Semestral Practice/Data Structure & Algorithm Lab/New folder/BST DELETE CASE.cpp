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
    // Delete function.
    BST* Delete(BST*, int);
    // Inorder, Preorder, Postorder traversal functions.
    void Inorder(BST*);
    void preorder(BST*);
    void postorder(BST*);
    void DFS_PreOrder(BST*);
    void DFS_inOrder(BST*);
    void DFS_postOrder(BST*);
};

// ... (Previous code remains the same)
// Default Constructor definition.
BST ::BST(){
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
	else if (value < root->data){
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
void BST:: DFS_PreOrder(BST* root){
	if (root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	DFS_PreOrder(root->left);
	DFS_PreOrder(root->right);
} 
void BST:: DFS_inOrder(BST* root){
	if (root==NULL){
		return ;
	}
	
	DFS_inOrder(root->left);
	cout<<root->data<<" ";
	DFS_inOrder(root->right);
} 
void BST:: DFS_postOrder(BST* root){
	if (root==NULL){
		return ;
	}
	
	DFS_postOrder(root->left);
	DFS_postOrder(root->right);
	cout<<root->data<<" ";
} 



BST* BST::Delete(BST* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = Delete(root->left, value);
    } else if (value > root->data) {
        root->right = Delete(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            BST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BST* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        BST* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

// Driver code
int main() {
    BST b, *root = NULL;
    root = b.Insert(root, 15);
    // Insert elements...
    b.Insert(root, 10);
	b.Insert(root, 20);
	b.Insert(root, 8);
	b.Insert(root, 12);
	b.Insert(root, 17);
	b.Insert(root, 25);

    // Deleting a node
    int key_to_delete = 20; // Example: deleting node with value 20
    cout << "Deleting node with value: " << key_to_delete << endl;
    root = b.Delete(root, key_to_delete);

    // Traversals
    cout << "Inorder traversal" << endl;
    b.Inorder(root);
    cout << "Preorder traversal" << endl;
    b.preorder(root);
    cout << "Postorder traversal" << endl;
    b.postorder(root);
    cout << "\n DFS_preorder traversal" << endl;
    b.DFS_PreOrder(root);
    cout << "\n DFS_inorder traversal" << endl;
    b.DFS_inOrder(root);
    cout << "\n DFS_postorder traversal" << endl;
    b.DFS_postOrder(root);

    return 0;
}

