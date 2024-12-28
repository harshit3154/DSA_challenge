#include <iostream>
#include <stdio.h>
#include "Queue.h"

using namespace std;

struct Node *root=nullptr;

void createTree(){
    struct Node *p,*t;
    struct Queue q;
    int x;

    create(&q,100);

    printf("\n\n\t\t\tEnter the root value : ");
    scanf("%d",&x);
    root=(Node *)malloc(sizeof(Node));
    root->data=x;
    root->lchild=root->rchild=nullptr;

    enqueue(&q,root);

    while(!isEmpty(&q)){
        p=dequeu(&q);
        printf("\n\n\n\t\tEnter the left child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
           t=(Node *)malloc(sizeof(Node));
           t->data=x;
           t->lchild=t->rchild=nullptr;
           p->lchild=t;
           enqueue(&q,t);
        }

        printf("\n\n\n\t\tEnter the right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
           t=(Node *)
           malloc(sizeof(Node));
           t->data=x;
           t->lchild=t->rchild=nullptr;
           p->lchild=t;
           enqueue(&q,t);
        }
          

    }
}

void preorder(Node *root){
    if(root==nullptr) return;
    cout<<"\n\n\t\t\t\t"<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(Node *root){
    if(root==nullptr) return;
    inorder(root->lchild);
    cout<<"\n\n\t\t\t\t"<<root->data;
    inorder(root->rchild);
}

void postorder(Node *root){
    if(root==nullptr) return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<"\n\n\t\t\t\t"<<root->data;
}

int main(){
    createTree();
    cout<<"\n\n\tPrinting the inorder traversal of tree  : ";
    inorder(root);
    cout<<"\n\n\tPrinting the preorder traversal of tree : ";
    preorder(root);
    cout<<"\n\n\tPrinting the postorder traversal of tree : ";
    postorder(root);
    return 0;
}