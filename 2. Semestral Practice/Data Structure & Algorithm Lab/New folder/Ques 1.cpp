// Question no 01
#include<iostream>
#include <queue>
using namespace std;
class BST{
	int data;
	BST* left;
	BST* right;
	public:
		BST();
		BST(int);
		BST* insert(BST* ,int ); 
		BST* Delete (BST*,int);
		void preorder(BST*);
		void inorder(BST*);
		void postorder(BST*);
		void DFS_preorder(BST*);
		void DFS_inorder(BST*);
		void DFS_postorder(BST*);
		void BFS_LevelOrder(BST*);
};
BST :: BST(){
	data=0;
	left=NULL;
	right=NULL;
}
BST :: BST(int value){
	data=value;
	left=NULL;
	right=NULL;
}
BST* BST::insert(BST* root,int value){
	if(root==NULL){
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
	cout<<root->data<<" "; 
	preorder(root->left);  
	preorder(root->right);
}
void BST::inorder(BST* root){
	if(root==NULL){
		return;
	}
	inorder(root->left); 
	cout<<root->data<<" ";
	inorder(root->right);
}
void BST::postorder(BST* root){
	if(root==NULL){
		return;
	}
	postorder(root->left); 
	postorder(root->right); 
	cout<<root->data<<" ";
}
BST* BST :: Delete (BST* root , int value){
    if(root==NULL){
		return root;
	}
	else{
	if(value<=root->data){
		root->left=Delete(root->left,value);
	}
	else if(value>root->data){
		root->right=Delete(root->right,value);
	}else {
        if (root->left == NULL) {
            BST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        BST* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}
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
int main(){
	BST b, *root=NULL; 
	root=b.insert(root,10);
	b.insert(root,5);
	b.insert(root,15);
	b.insert(root,3);
	b.insert(root,7);
	b.insert(root,12);
	b.insert(root,18);
	b.insert(root,2);
	b.insert(root,4);
	b.insert(root,6);
	b.insert(root,8);
	b.insert(root,11);
	b.insert(root,14);
	b.insert(root,13);
	b.insert(root,19);
	b.insert(root,20);
	b.insert(root,25);
// Now inserting the said nodes
	b.insert(root,25);
	b.insert(root,12);
    cout << "a. In Order Traveral" << endl;
    b.inorder(root);
    cout << "\nb. Pre Order Traveral" << endl;
    b.preorder(root);
    cout << "\nc. Post Order Traveral" << endl;
    b.postorder(root);
    cout << "\nd. Level Order Traversal" << endl;
    b.BFS_LevelOrder(root);
	cout << "\ne. Node to be deleted is  15 " << endl;
	int key_to_be_deleted = 15;
	root = b.Delete(root,key_to_be_deleted);
	cout << "Node Has been deleted " << endl;
	
	return 0;
}
