#include <iostream>
#include <stdio.h>
#include "Queue4.h"

using namespace std;

class Tree{

    private : 
        Node *root=nullptr;
        int *ele;
    public : 
        Node* GetRoot();
        void CreateTree();
        void Preorder(Node*);
        void InOrder(Node*);
        void PostOrder(Node*);
        void LevelOrderTraversal(Node*);
        int Height(Node*);
};
int main(){
    Tree t;
    t.CreateTree();
    t.Preorder(t.GetRoot());
    t.PostOrder(t.GetRoot());
    t.InOrder(t.GetRoot());
    t.LevelOrderTraversal(t.GetRoot());
    t.Height(t.GetRoot());
    return 0;
}

void Tree::CreateTree() {
    Queue *q = new Queue(100); // Create a queue with a capacity of 100
    int x;
    cout << "\n\n\t\tEnter the data of root element: ";
    cin >> x;
    root = new Node(x); // Initialize the root node
    q->enqueue(root); // Enqueue the root node

    while (!q->isEmpty()) {
        Node *p = q->dequeue(); // Dequeue the front node

        cout << "Enter left child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if (x != -1) {
            Node *temp = new Node(x);
            p->lchild = temp; // Link to the left child
            q->enqueue(temp); // Enqueue the new node
        }

        cout << "Enter right child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if (x != -1) {
            Node *temp = new Node(x);
            p->rchild = temp; // Link to the right child
            q->enqueue(temp); // Enqueue the new node
        }
    }
}

Node* Tree::GetRoot(){  return root; }

void Tree::Preorder(Node *root){
    cout<<root->data<<"\t";
    Preorder(root->lchild);
    Preorder(root->rchild);
}

void Tree::InOrder(Node* root){
    InOrder(root->lchild);
    cout<<root->data<<"\t";
    InOrder(root->rchild);
}

void Tree::PostOrder(Node* root){
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout<<root->data<<"\t";
}

void Tree::LevelOrderTraversal(Node* root){
    Queue *q=new Queue(100);
    q->enqueue(root);
    while(!q->isEmpty()){
        Node *temp=q->dequeue();
        cout<<temp->data;
        if(temp->lchild){
            q->enqueue(temp->lchild);
        }
        if(temp->rchild){
            q->enqueue(temp->rchild);
        }
    }
}

int Tree::Height(Node* root){
    if(!root) return 0;
    return max(Height(root->lchild),Height(root->rchild))+1;
}