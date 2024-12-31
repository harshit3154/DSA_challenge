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

int height(Node* root){
    int hls=root->lchild?root->lchild->height:0;
    int hrs=root->rchild?root->rchild->height:0;
    return hls>hrs?hls+1:hrs+1;
}

int balanceFactor(Node* root){
    int hl=root->lchild?root->lchild->height:0;
    int hr=root->rchild?root->rchild->height:0;
    return hl-hr;
}

Node* LLRotation(Node* p){
    Node* pl=p->lchild;
    Node* plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=height(p);
    pl->height=height(pl);
    return pl;
}

Node* LRRotation(Node* p){
    Node* pl=p->lchild;
    Node* plr=pl->rchild;
    Node* temp=pl->lchild;
    pl->lchild=plr;
    pl->rchild=temp;
    plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    return pl;
}

Node* RRRotation(Node* p){
    Node* pr=p->rchild;
    Node* prl=pr->lchild;
    pr->lchild=p;
    p->rchild=prl;
    return pr;
}

Node* RLRotation(Node* p){
    Node* pr=p->rchild;
    Node* prl=pr->lchild;
    return pr;
}


Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
     if(val<root->data){
        root->lchild=insert(root->lchild,val);
    }else if(val>root->data){
        root->rchild=insert(root->rchild,val);
    }
    return root;
}

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<"\t"<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->lchild);
    cout<<"\t"<<root->data;
    inorder(root->rchild);
}

void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<"\t"<<root->data;
}

void display(Node* root){
    cout<<"\n\n\n\t\tThe inorder traversal of the tree is\n\n\t\t\t\t:";
    inorder(root);
    cout<<"\n\n\n\t\tThe preorder traversal of the tree is\n\n\t\t\t\t:";
    preorder(root);
    cout<<"\n\n\n\t\tThe postorder traversal of the tree is\n\n\t\t\t\t:";
    postorder(root);
}


Node* insertNode(Node* root,int val){
    if(root) cout<<"\n\n\t\tThe root value is : "<<root->data;
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->lchild=insertNode(root->lchild,val);
    }else if(val>root->data){
        root->rchild=insertNode(root->rchild,val);
    }
    root->height=height(root);
    printf("\n\n\n\n\t\tTHe value of root is %d and the height is %d.",root->data,root->height);
    if(balanceFactor(root)==2 && balanceFactor(root->lchild)==1){
        cout<<"\n\n\t\tInside LL Rotation";
        return LLRotation(root);
    }else if(balanceFactor(root)==2 && balanceFactor(root->lchild)==-1){
        return LLRotation(root);
    }else if(balanceFactor(root)==-2 && balanceFactor(root->rchild)==-1){
        return LLRotation(root);
    }else if(balanceFactor(root)==-2 && balanceFactor(root->rchild)==1){
        return LLRotation(root);
    }
    return root;
}

int main(){
    Node* root=NULL;
    cout<<"\n\n\t\t-------------Creating the tree--------------";
    root=insert(root,7);
    insert(root,4);
    insert(root,1);
    display(root);
    delete root;
    root=NULL;
    root=insertNode(root,7);
    root=insertNode(root,4);
    root=insertNode(root,1);
    display(root);
    return 0;
}
