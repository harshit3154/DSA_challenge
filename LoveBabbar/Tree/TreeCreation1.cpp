#include <iostream>

using namespace std;
class Node{
    public:
        int data;
        Node *lchild,*rchild;
        Node(int data){
            this->data=data;
            this->lchild=this->rchild=nullptr;
        }
};

class Queue{
    private :
        int front,rear,size;
        Node **ele;
    public :
        Queue(int size){
            this->size=size;
            ele=new Node*[size];
            front=rear=0;
        }

        void enqueue(Node*);
        Node* dequeue();
        bool isEmpty();
};

void Queue::enqueue(Node* root){
    if((rear+1)%size==front){
        cout<<"\n\n\n\t\tFULL";
        return;
    }
    ele[rear++]=root;
}

Node* Queue::dequeue(){
    if(front==rear){
        cout<<"\n\n\t\tEmpty";
        return nullptr;
    }
    return ele[front++];
}

bool Queue::isEmpty(){
    return front==rear;
}

Node* createTree(Node* root){
    int val;
    cout<<"\n\n\n\t\t\tEnter the data for inserting in the node : ";
    cin>>val;
    if(val==-1)
        return nullptr;
    root=new Node(val);
    root->lchild=createTree(root->lchild);
    root->rchild=createTree(root->rchild);
    return root;
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->lchild);
    cout<<"\t"<<root->data;
    inorder(root->rchild);
}

void preorder(Node* root){
    if(!root)   return;
    cout<<"\t"<<root->data;
    inorder(root->lchild);
    inorder(root->rchild);
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<"\t"<<root->data;
}

void levelordertraversal(Node* root){
    Queue *q=new Queue(100);
    cout<<"\n\n\n\t\tTraversing level order of a tree\n\n\t\t:";
    q->enqueue(root);
    while(!q->isEmpty()){
        Node* temp=q->dequeue();
        cout<<"\t"<<temp->data;
        q->enqueue(temp->lchild);
        q->enqueue(temp->rchild);
    }
}

int max(int x,int y){
    return x>y?x:y;
}

int height(Node* root){
    if(!root) return 0;
    return max(height(root->lchild),height(root->rchild))+1;
}

int inPre(Node* root){
    if( !root->rchild) return root->data;
    inPre(root->rchild);
}

int inSuc(Node* root){
    if(!root->lchild) return root->data;
}

Node* DeleteNode(Node *root,int val){
    Node *tail=root;
    while(!root){
        t
    }
}
int main(){
    return 0;
}