#include<iostream>
using namespace std;
class BST{
	int data;
	BST* left;
	BST* right;
	public:
		// default constructor 
		BST();
		// parametrize constructor 
		BST(int);
		//insert function 
		BST* insert(BST* ,int );
		// preorder treversing 
		void preorder(BST*);
		// inorder treversing
		void inorder(BST*);
		// postorder treversing
		void postorder(BST*);
		void DFS_preorder(BST*);
		void DFS_inorder(BST*);
		void DFS_postorder(BST*);
		void BFS_Levelordertreversing(BST*);
		
		
	
};
// default contructor 
BST :: BST(){
	data=0;
	left=NULL;
	right=NULL;
}
//parametrize constructor 
BST :: BST(int value){
	data=value;
	left=NULL;
	right=NULL;
}
//insert function definition
BST* BST::insert(BST* root,int value){
	if(root==NULL){
//		BST* newBSTNode =new BST(value);
//		NewBSTNode->data=data;
//		NewBSTNode->left=NULL;
//		NewBSTNode->right=NULL;
//		return NewBSTNode;
		
		return new BST(value);
	}
	if(value<=root->data){
		root->left=insert(root->left,value);
	}
	else if(value>root->data){
		root->right=insert(root->right,value);
	}
	return root;
}
void BST::preorder(BST* root){
	if(root==NULL){
		return;
	}
	//preorder treversing   root left right
	cout<<root->data<<endl; //root
	preorder(root->left);  //left
	preorder(root->right); //right
}
void BST::inorder(BST* root){
	if(root==NULL){
		return;
	}
	//inorder treversing  left root  right
	 
	inorder(root->left);  //left
	//root
	cout<<root->data<<endl;
	inorder(root->right); //right
}
void BST::postorder(BST* root){
	if(root==NULL){
		return;
	}
	//inorder treversing  left root  right
	 
	postorder(root->left);  //left
	
	postorder(root->right); //right
	//root
	cout<<root->data<<endl;
}
int main(){
	BST b, *root=NULL; //root is empty 
	root=b.insert(root,15);
	b.insert(root,10);
	b.insert(root,20);
	b.insert(root,8);
	b.insert(root,12);
	b.insert(root,17);
	b.insert(root,25);
	cout<<"preorder treversing:"<<endl;
	b.preorder(root);
	cout<<"inorder treversing:"<<endl;
	b.inorder(root);
	cout<<"postorder treversing:"<<endl;
	b.postorder(root);
	
	
	
	
	
	return 0;
	
}
