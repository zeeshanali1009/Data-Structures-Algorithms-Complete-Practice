#include <iostream>
#include <queue>
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
	void Inorder(BST*);
	void preorder(BST*);
	void postorder(BST*);
	void DFS_InOrder(BST*);
	void DFS_PreOrder(BST*);
	void DFS_PostOrder(BST*);
	void BFS_LevelOrder(BST*);
};

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
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}
void BST ::preorder(BST* root)
{
	if (root==NULL) {
		return;
	}
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}
void BST ::postorder(BST* root)
{
	if (root==NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}
void BST ::DFS_PreOrder(BST* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    DFS_PreOrder(root->left);
    DFS_PreOrder(root->right);
}

void BST ::DFS_InOrder(BST* root) {
    if (root == NULL) {
        return;
    }
    DFS_InOrder(root->left);
    cout << root->data << " ";
    DFS_InOrder(root->right);
}

void BST ::DFS_PostOrder(BST* root) {
    if (root == NULL) {
        return;
    }
    DFS_PostOrder(root->left);
    DFS_PostOrder(root->right);
    cout << root->data << " ";
}
void BST::BFS_LevelOrder(BST* root) {
    if (root == NULL) {
        return;
    }

    queue<BST*> q;
    q.push(root);

    while (q.empty()==NULL) {
        BST* current = q.front();
        cout << current->data << " ";
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
        q.pop();
    }
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 15);
	
	b.Insert(root, 10);
	b.Insert(root, 20);
	b.Insert(root, 8);
	b.Insert(root, 12);
	b.Insert(root, 17);
	b.Insert(root, 25);
	
	cout<<"inorder treversing:"<<endl;
	b.Inorder(root);
	
	cout<<"preorder treversing:"<<endl;
	b.preorder(root);
	
	cout<<"postorder treversing:"<<endl;
	b.postorder(root);
	
	cout << "\nDFS Preorder traversal: " << endl;
    b.DFS_PreOrder(root);

    cout << "\nDFS Inorder traversal: " << endl;
    b.DFS_InOrder(root);

    cout << "\nDFS Postorder traversal: " << endl;
    b.DFS_PostOrder(root);

    cout << "\nBFS Level Order traversal: " << endl;
    b.BFS_LevelOrder(root);
	return 0;
}

