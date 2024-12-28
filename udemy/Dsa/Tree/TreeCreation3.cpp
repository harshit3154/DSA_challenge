#include <iostream>
#include <stdio.h>
#include "Queuet.h"

using namespace std;
template <class T>
class Tree{
    private : 
        struct Node{
            T data;
            Node *lchild,*rchild;
        }
        Queue<Node> q(100);
    public:
        void createTree(T *ele){
            struct Node *p,*t;
            int i=0;
            T x;
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
};
int main(){

    return 0;
}