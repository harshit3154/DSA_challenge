#include <iostream>

using namespace std;

//Definining node for the tree.
class Node{
	public : 
		int data,height;
		Node *lchild,*rchild;
		Node(int data){
			this->data=data;
			this->height=1;
			this->lchild=this->rchild=NULL;
		}
};

//Defining Tree class to handle all the method of tree.
class Tree{
	private : 
		Node* root;
	public : 
		Tree(){
			root=NULL;
		}
		Node* getRoot();
		void setRoot(Node*);
		int height(Node*);
		int balanceFactor(Node*);
		Node* LLRotation(Node*);
		Node* LRRotation(Node*);
		Node* RRRotation(Node*);
		Node* RLRotation(Node*);
		Node* RInsert(Node*,int);
		void inorder(Node*);
		void preorder(Node*);
		void postorder(Node*);
		int inorderPre(Node*);
		int inorderSuc(Node*);
		Node* deleteNode(Node*,int);
};

void display(Tree* tree){
	cout<<"\n\n\t\tThe inorder traversal of tree is\n\n\t\t\t:";
	tree->inorder(tree->getRoot());
	cout<<"\n\n\t\tThe preorder traversal of tree is\n\n\t\t\t:";
	tree->preorder(tree->getRoot());
	cout<<"\n\n\t\tThe postorder traversal of tree is\n\n\t\t\t:";
	tree->postorder(tree->getRoot());
}

int main(){
	Tree* tree=new Tree();
	for(int i=10;i>=1;i--){
		tree->setRoot(tree->RInsert(tree->getRoot(),i));
	}
	display(tree);
	delete(tree->getRoot());
	tree->setRoot(NULL);
	for(int i=20;i>10;i--){
		tree->setRoot(tree->RInsert(tree->getRoot(),i));
	}
	display(tree);
	return 0;
}

Node* Tree::getRoot(){
	return root;
}

void Tree::setRoot(Node* p){
	this->root=p;
}
int Tree::height(Node* p){
	if(p==NULL) return 0;
	int l=(p->lchild==NULL)?0:p->lchild->height;
	int r=(p->rchild==NULL)?0:p->rchild->height;
	return l>r?l+1:r+1;
}

int Tree::balanceFactor(Node *p){
	if(!root) return 0; 
	return height(p->lchild)-height(p->rchild);
}

Node* Tree::LLRotation(Node *p){
	Node* pl=p->lchild;
	Node* plr=pl->rchild;
	pl->rchild=p;
	p->lchild=plr;
	pl->height=height(pl);
	p->height=height(p);
	if(p==root)
		root=pl;
	return pl;
}

Node* Tree::LRRotation(Node* p){
	Node* pl=p->lchild;
	Node* plr=p->rchild;
	Node* plrl=plr->lchild;
	Node* plrr=plr->rchild;
	plr->lchild=pl;
	plr->rchild=p;
	p->lchild=plrr;
	pl->rchild=plrl;
	p->height=height(p);
	pl->height=height(pl);
	plr->height=height(plr);
	if(p==root)
		root=plr;
	return plr;
}

Node* Tree::RRRotation(Node* p){
	Node* pr=p->rchild;
	Node* prl=pr->lchild;
	pr->lchild=p;
	p->rchild=prl;
	p->height=height(p);
	pr->height=height(pr);
	prl->height=height(prl);
	if(root==p)
		root=pr;
	return pr;
}

Node* Tree::RLRotation(Node* p){
	Node* pr=p->rchild;
	Node* prl=pr->lchild;
	Node* l=prl->lchild;
	Node* r=prl->rchild;
	prl->lchild=p;
	prl->rchild=pr;
	p->rchild=l;
	pr->lchild=r;
	p->height=height(p);
	pr->height=height(pr);
	prl->height=height(prl);
	if(p==root)
		root=prl;
	return prl;
}

Node* Tree::RInsert(Node* root,int val){
	if(!root)
		return new Node(val);
	if(val<root->data){
		root->lchild=RInsert(root->lchild,val);
	}else if(val>root->data){
		root->rchild=RInsert(root->rchild,val);
	}
	root->height=height(root);
	
	// checking for the balance of avl tree.
	if( balanceFactor(root)==2 && balanceFactor(root->lchild)==1)
		return LLRotation(root);
	else if(balanceFactor(root)==2 && balanceFactor(root->lchild)==-1)
		return LRRotation(root);
	else if(balanceFactor(root)==-2 && balanceFactor(root->rchild)==-1)
		return RRRotation(root);
	else if(balanceFactor(root)==-2 && balanceFactor(root->rchild)==1)
		return RLRotation(root);
		
	return root;
}

void Tree::inorder(Node* root){
	if(!root)	return ;
	inorder(root->lchild);
	cout<<"\t"<<root->data;
	inorder(root->rchild);
}

void Tree::preorder(Node* root){
	if(!root)	return ;
	cout<<"\t"<<root->data;
	preorder(root->lchild);
	preorder(root->rchild);
}

void Tree::postorder(Node* root){
	if(!root)	return ;
	postorder(root->lchild);
	postorder(root->rchild);
	cout<<"\t"<<root->data;
}
