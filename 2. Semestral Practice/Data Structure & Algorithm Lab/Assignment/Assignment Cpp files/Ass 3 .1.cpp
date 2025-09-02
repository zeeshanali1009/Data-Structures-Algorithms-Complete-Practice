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
	void preorder(BST*);
	void postorder(BST*);
	void DFS_InOrder(BST*);
	void DFS_PreOrder(BST*);
	void DFS_PostOrder(BST*);
	void BFS_LevelOrder(BST*);
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
    cout << "\nBFS Level Order traversal: " << endl;
    b.BFS_LevelOrder(root);
	return 0;
}

