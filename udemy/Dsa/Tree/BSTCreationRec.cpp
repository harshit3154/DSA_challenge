#include <iostream>
#include <stdio.h>

using namespace std;
class Node{
    public :
        int data;
        Node *lchild,*rchild;
        Node(int data){
            this->data=data;
            this->lchild=this->rchild=nullptr;
        }
};

class BST{
    private : 
        Node *root;
    public :
        BST(){
            root=nullptr;
        }

        void setRoot(Node*);
        Node* getRoot();
        Node* RecCreateTree(Node*,int);
        void IteCreateTree(Node*,int);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
};

int main(){

    BST *bst=new BST();
    int ch;
    do{
        cout<<"\n\nEnter : \n\n\t\t1 -----> for creating the tree.\n\n\t\t2  -----> for traversing the preorder. \n\n\t\t 3 ------> for traversing inorder.";
        cout<<"\n\n\t\t\tEnter the choices : ";
        cin>>ch;
        switch(ch){
            case 1: 
                int x;
                cout<<"\n\n\t\tEnter the value to be insert inside the root : ";
                cin>>x;
                // bst->setRoot(bst->RecCreateTree(bst->getRoot(),x));/
                bst->IteCreateTree(bst->getRoot(),x);
                break;
            case 2:
                cout<<"\n\n\n\t\tThe inorder traversal of the tree is\n\n\t\t\t:";
                bst->preorder(bst->getRoot());
                break;
            case 3:
                cout<<"\n\n\n\t\tThe preorder traversal of the tree is\n\n\t\t\t:";
                bst->inorder(bst->getRoot());
                break;
            default : 
                cout<<"\n\n\t\t\t______________Enter valid choice._____________";

        }
    }while(ch<99);
    return 0;
}

Node* BST::getRoot(){
    return root;
}

void BST::setRoot(Node* r){
    this->root=r;
}
void BST::IteCreateTree(Node* root,int x){
    if(!root){
        setRoot(new Node(x));
    }
    Node *temp=root;
    while(temp){
        if(temp->data==x){
            cout<<"\n\n\t\tDuplicate element cannot be inserted.";
            return;
        }else if(x<temp->data){
            if(!temp->lchild){
                temp->lchild=new Node(x);
            }else
                temp=temp->lchild;
        }else{
            if(!temp->rchild){
                temp->rchild=new Node(x);
                return;
            }else{
                temp=temp->rchild;
            }
        }
    }
}

Node* BST::RecCreateTree(Node *root,int x){
      if(!root){
        cout<<"\n\n\t\tReturning new node";
        return new Node(x);
      } 
      else if(root->data==x){
        cout<<"\n\n\n\t\t\tDuplicate element cannot be inserted.";
        return nullptr;
      }else if(root->data>x){
        cout<<"\n\n\t\tcalling left child";
        root->lchild=RecCreateTree(root->lchild,x);
      }else{
        cout<<"\n\n\t\tcalling right child.";
        root->rchild=RecCreateTree(root->rchild,x);
      }
      return root;
}

void BST::inorder(Node* root){
    if(!root)   return;
    inorder(root->lchild);
    cout<<root->data<<"\t";
    inorder(root->rchild);
}

void BST::preorder(Node *root){
    if(!root)   return;
    cout<<root->data<<"\t";
    preorder(root->lchild);
    preorder(root->rchild);
}

void BST::postorder(Node *root){
    if(!root)   return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<"\t";
}