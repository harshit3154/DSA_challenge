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
        void createBST();
        Node* getRoot();
        void preorder(Node*);
        void insertNode(int);
        void inorder(Node*);
};

int main(){
    BST *bst=new BST();

    int ch;
    char choice;
    do{
        cout<<"\n\nEnter : \n\n\t\t1 -----> for creating the tree.\n\n\t\t2  -----> for traversing the preorder. \n\n\t\t 3 ------> for traversing inorder.";
        cout<<"\n\n\t\t\tEnter the choices : ";
        cin>>ch;
        switch(ch){
            case 1: 
                bst->createBST();
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
        cout<<"Do you want to continue(Y/N) : ";
        cin>>choice;
    }while(choice=='y'|| choice=='Y');
    return 0;
}

Node* BST::getRoot(){
    return root;
}

void BST::createBST(){
    int x=0;
    while(x!=-1){
        cout<<"\n\n\n\t\tEnter the element to insert in BST and -1 to exit : ";
        cin>>x;
        if(x!=-1){
            insertNode(x);
        }
    }
}

void BST::insertNode(int x){

    if(root==nullptr){
        root=new Node(x);
        return;
    }

    Node *temp=root,*tail=nullptr;
    while(temp!=nullptr){
        tail=temp;
        if( temp->data==x ){
            cout<<"\n\n\t\t\t\tDuplicate element cannot be inserted";
            return;
        }else if(x<temp->data){
            temp=temp->lchild;
        }else{
            temp=temp->rchild;
        }
    }
    if(x<tail->data){
        tail->lchild=new Node(x);
    }else{
        tail->rchild=new Node(x);
    }

}

void BST::preorder(Node *root){
    cout<<root->data<<"\t";
}
void BST::inorder(Node *root){
    if(!root)   return;
    inorder(root->lchild);
    cout<<root->data<<"\t";
    inorder(root->rchild);
}