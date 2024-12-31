#include <iostream>

using namespace std;
class Node{
	
	public : 
	
		int data,height;
		
		Node *lchild,*rchild;
		
		Node(int data){
			this->data=data;
			this->height=1;
			lchild=rchild=NULL;
		}
};

int max(int x,int y){
	return x>y?x:1;
}

int height(Node* root){
	if(!root) return 0;
	int hl=root->lchild?1:0;
	int hr=root->rchild?1:0;
	return max(hl,hr)+1;
}

int balanceFactor(Node* root){
	if(!root)	return 0;
	int hl=root->lchild?root->lchild->height:0;
	int hr=root->rchild?root->rchild->height:0;
	return hl-hr;
}

Node* LLRotation(Node* root){
	if(!root) return NULL;
	Node* pl=root->lchild;
	Node* plr=root->rchild;
	pl->rchild=root;
	root->lchild=plr;
	return pl;
}

Node* LRRotation(Node* root){
	if(!root) return NULL;
	Node* pl=root->lchild;
	Node* plr=pl->rchild;
	pl->rchild=pl->lchild;
	pl->lchild=plr;
	return LLRotation(root);
}

Node* insert(Node* root,int val){
	
	if(!root)
		return new Node(val);
		
	if(val<root->data)
		root->lchild=insert(root->lchild,val);
	else if(val>root->data)
		root->rchild=insert(root->rchild,val);	
	
	//recalculating and assigning height of root.
	root->height=height(root);
	
	//Checking for the balance factor to perform rotation.
	
	//condition for ll rotation
	if( balanceFactor(root)==2 && balanceFactor(root->lchild)==1){
		return LLRotation(root);
	}
	
	//condition for lr rotation
	if(balanceFactor(root)==2 && balanceFactor(root->lchild)==-1){
		return LRRotation(root);
	}
	return root;
}

void preorder(Node* root){
	if(!root) return;
	cout<<"\t"<<root->data;
	preorder(root->lchild);
	preorder(root->rchild);
}

void inorder(Node* root){
	if(!root)	return;
	inorder(root->lchild);
	cout<<"\t"<<root->data;
	inorder(root->rchild);
}

void postorder(Node* root){
	if(!root)	return;
	postorder(root->lchild);
	postorder(root->rchild);
	cout<<"\t"<<root->data;
}

void display(Node* root){
	cout<<"\n\n\t\tThe inorder traversal of the tree are\n\n\t\t\t\t:";
	inorder(root);
	cout<<"\n\n\t\tThe preorder traversal of the tree are\n\n\t\t\t\t:";
	preorder(root);
	cout<<"\n\n\t\tThe postorder traversal of the tree are\n\n\t\t\t\t:";
	postorder(root);
	
}
int main(){
	Node* root=NULL;
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,7);
	display(root);
	return 0;
}
