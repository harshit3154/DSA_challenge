#include <iostream>
#include <stdio.h>
#include "Queue.h"

using namespace std;
struct Node *root=nullptr;

int height(Node*);
void createTree(int *ele){
    struct Queue q;
    struct Node *p,*t;
    int i=0;
    int x;
    create(&q,200);
    root=(Node *)malloc(sizeof(Node));
    root->data=ele[i++];
    root->lchild=root->rchild=nullptr;
    enqueue(&q,root);
    while(!isEmpty(&q)){
        p=dequeu(&q);
        x=ele[i++];
        if(x!=-1){
            t=(Node *)malloc(sizeof(Node));
            t->lchild=t->rchild=nullptr;
            t->data=x;
            p->lchild=t;
            enqueue(&q,t);
        }
        x=ele[i++];
        if(x!=-1){
            t=(Node *)malloc(sizeof(Node));
            t->lchild=t->rchild=nullptr;
            t->data=x;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(Node *root){
    if(root==nullptr) return;
    cout<<"\t"<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(Node *root){
    if(root==nullptr) return;
    inorder(root->lchild);
    cout<<"\t"<<root->data;
    inorder(root->rchild);
}

void postorder(Node *root){
    if(root==nullptr) return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<"\t"<<root->data;
}

void levelOrderTraversal(Node *root){
    struct Queue q;
    create(&q,100);
    enqueue(&q,root);
    while(!isEmpty(&q)){
        Node *p=dequeu(&q);
        cout<<"\t"<<p->data;
        if(p->lchild){
            enqueue(&q,p->lchild);
        }
        if(p->rchild){
            enqueue(&q,p->rchild);
        }
    }
}

void subtree(Node *root){
    if(root==nullptr)
        return;
    subtree(root->lchild);
    cout<<"\n\n\t\tDisplaying subtree level order traversal \n\n\t\t\t: ";
    levelOrderTraversal(root);
    subtree(root->rchild);
    printf("\n\n\t\t\tThe height of this subtree is : %d ",height(root));
}

int height(Node *root){
    if(root==nullptr)   return 0;
    return max(height(root->lchild),height(root->rchild))+1;
}

int main(){
    // int ar[]={1,2,3,-1,-1,-1,-1};

    int ar[]={1,2,3,4,5,6,7,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    createTree(ar);
    cout<<"\n\n\tPrinting the inorder traversal of tree  \n\n\t\t\t: ";
    inorder(root);
    cout<<"\n\n\tPrinting the preorder traversal of tree \n\n\t\t\t: ";
    preorder(root);
    cout<<"\n\n\tPrinting the postorder traversal of tree \n\n\t\t\t: ";
    postorder(root);
    cout<<"\n\n\tPrinting the level traversal of tree \n\n\t\t\t: ";
    levelOrderTraversal(root);
    subtree(root);
    return 0;
}