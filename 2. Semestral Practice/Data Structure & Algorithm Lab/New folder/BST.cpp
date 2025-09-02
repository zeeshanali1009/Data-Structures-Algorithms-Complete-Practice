#include <iostream>
#include <queue>
using namespace std;
class BST{
	public:
	int data;
	BST*left;
	BST*right;
	public:
		BST();
		BST(int);
		BST* Insert(BST*,int);
		BST* Delete(BST*,int);
		void Preorder(BST*);
		void Inorder(BST*);
		void Postorder(BST*);
		void DFS_Preorder(BST*);
		void DFS_Inorder(BST*);
		void DFS_Postorder(BST*);
		void levelordertraversing(BST*);
};
BST::BST(){
	data = 0;
	left = right = NULL;
}
BST::BST(int value){
	data = value ;
	left = right = NULL;
}
BST* BST::Insert(BST*root,int value){
	if (root==NULL){
		return new BST(value);
	}
	else {
		if (value<=root->data){
			root->left = Insert(root->left,value);
		}
		else if (value<=root->data){
			root->right = Insert(root->right,value);
		}
	}
}
BST* Delete (BST*root,int value){
	if (root == NULL){
		return root;
	}
	if (value<=root->data){
			root->left = Delete(root->left,value);
		}
		else if (value<=root->data){
			root->right = Delete(root->right,value);
		}
		if(root->left == 0){
			BST * temp = root->right;
			delete root;
			return temp;
		}
		if(root->right == 0){
			BST * temp = root->left;
			delete root;
			return temp;
		}
		BST * temp = root->right;
		while(temp->left!= NULL){
			temp = temp->left;
		}
		root->data = temp->data;
		root->right = Delete(root->right,temp->data);
}
void BST::levelordertraversing(BST*root){
	queue<BST*>q;
	q.push(root);
	while(q.empty()==NULL){
		BST*current = q.front();
		cout << current->data<<" ";
		if(current->left == NULL){
			q.push(current->left);
		}
		if(current->right == NULL){
			q.push(current->right);
		}
		q.pop();
	}
}
int main()
{
	
}
