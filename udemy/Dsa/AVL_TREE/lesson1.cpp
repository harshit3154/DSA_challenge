#include <iostream>
#include <stdio.h>

using namespace std;
struct Node{
    struct Node *lchild,*rchild;
    int data,height;
};

Node *root=nullptr;

void display(Node *root){
    cout<<"\n\n\n\t\tThe node data are : ";
    cout << "\n\n\t\t\t\tThe value of root is : " << root->data;
    cout<<"\n\n\t\t\t\tThe left child is : "<<root->lchild->data;
    cout<<"\n\n\t\t\t\tThe right child is : "<<root->rchild->data;
}

int NodeHeight(struct Node *p){
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p){
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl-hr;
}

struct Node * LLRotation(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(pl);
    pl->height=NodeHeight(pl);
    if(root==p)
        root=pl;
    return pl;
}

struct Node * LRRotation(struct Node *p){
    return NULL;
}

struct Node * RRRotation(struct Node *p){
    return NULL;
}

struct Node * RLRotation(struct Node *p){
    return NULL;
}

struct Node* RInsert(struct Node *p,int data){
    
    if(p==nullptr){
       struct Node *t=new Node();
        t->data=data;
        t->height=1;
        t->rchild=t->rchild=nullptr;
        return t;
    }else if(p->data>data){
        p->lchild=RInsert(p->lchild,data);
    }else{
        p->rchild=RInsert(p->rchild,data);
    }
    display(p);
    p->height=NodeHeight(p);
    int bf=BalanceFactor(p);
    if(bf==2 && BalanceFactor(p->lchild)==1){
        return LLRotation(p);
    }else if(bf==2 && BalanceFactor(p->lchild)==-1){
        return LRRotation(p);
    }else if(bf==2 && BalanceFactor(p->rchild)==-1){
        return RRRotation(p);
    }else if(bf==-2 && BalanceFactor(p->rchild)==1){
        return RLRotation(p);
    }else{}
    return p;
}

int main(){

    cout<<"\t\t\t____________Welcome to AVL Tree Lessoon _____________________";

    root=RInsert(root,4);
    root=RInsert(root,3);
    root=RInsert(root,2);
    
    display(root);

    return 0;
}