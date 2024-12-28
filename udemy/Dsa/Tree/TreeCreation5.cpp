#include "Queue1.h"

class Tree{

    private : 
        Node *root;
        Queue *q;
    public :
        Tree(){
            root=nullptr;
            q=new Queue(100);
        }

        void createTree();

        void InOrder(Node*);

        void inorder(){
            cout<<"\n\n\t\tThe inorder traversal of the tree : ";
            InOrder(this->root);
        }

        void PostOrder(Node*);

        void postorder(){
            cout<<"\n\n\t\tThe postorder traversal of the tree : ";
            PostOrder(this->root);
        }

        void PreOrder(Node*);

        void preorder(){
            cout<<"\n\n\t\tThe preorder traversal of the tree : ";
            PreOrder(this->root);
        }
        
        int Height(Node*);

        void height(){
            cout<<"\n\n\t\tThe height of the tree is : "<<Height(root);
        }

        int Count(Node*);
        void count(){
            cout<<"\n\nt\t\tThe number of the node present in the tree is : "<<Count(root);
        }

        int TwoDegreeCount(Node*);
        void twoDegreeCount(){
            cout<<"\n\nt\t\tThe number of the node present in the tree is : "<<TwoDegreeCount(root);
        }

        int HeightOfTree(Node*);
        void heightOfTree(){
            cout<<"\n\n\t\tThe result of the question (if(x>y) return x else return y is : "<<HeightOfTree(root);
        }

        int NoOfLeafNode(Node*);
        void noOfLeafNode(){
            cout<<"\n\n\t\tThe number of leaf node is : "<<NoOfLeafNode(root);
        }
};

int main(){
    Tree *t=new Tree();
    t->createTree();
    t->inorder();
    t->preorder();
    t->postorder();
    t->height();
    t->count();
    t->twoDegreeCount();
    t->heightOfTree();
    t->noOfLeafNode();
    return 0;
}

void Tree::createTree(){

    int x;
    cout<<"\n\n\t\tEnter the value of root : ";
    cin>>x;
    root=new Node(x);
    q->enqueue(root);
    while(!q->isEmpty()){
        Node *temp=q->dequeue();
        cout<<"\n\n\t\t\tEnter the left child of "<<temp->data<<" : ";
        cin>>x;
        if(x==-2) break;
        if(x!=-1){
            temp->lchild=new Node(x);
            q->enqueue(temp->lchild);
        }
        cout<<"\n\n\t\t\tEnter the right child of "<<temp->data<<" : ";
        cin>>x;
        if(x!=-1){
            temp->rchild=new Node(x);
            q->enqueue(temp->rchild);
        }
    }
}

void Tree::InOrder(Node *root){
    if(!root)
        return;
    InOrder(root->lchild);
    cout<<"\t"<<root->data;
    InOrder(root->rchild);
}

void Tree::PreOrder(Node *root){
    if(!root)
        return;
    cout<<"\t"<<root->data;
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

void Tree::PostOrder(Node *root){
    if(!root)
        return;
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout<<"\t"<<root->data;
}

int Tree::Height(Node *root){
    if(!root) return 0;
    return max(Height(root->lchild),Height(root->rchild))+1;
}

int Tree::Count(Node* root){
    if(!root)
        return 0;
    return Count(root->lchild)+Count(root->rchild)+1;
}

int Tree::HeightOfTree(Node *root){
    if(!root)
        return 0;
    int x=HeightOfTree(root->lchild);
    int y=HeightOfTree(root->rchild);
    if(x>y)
        return x+1;
    else 
        return y+1;
}

int Tree::NoOfLeafNode(Node *root){
    if(!root->lchild && !root->rchild)
        return 1;
    return NoOfLeafNode(root->lchild)+NoOfLeafNode(root->rchild);
}

int Tree::TwoDegreeCount(Node *root){
    if(!root)
        return 0;
    if(root->lchild && root->rchild){
        return TwoDegreeCount(root->lchild)+TwoDegreeCount(root->rchild)+1;
    }
    return TwoDegreeCount(root->lchild)+TwoDegreeCount(root->rchild);
}