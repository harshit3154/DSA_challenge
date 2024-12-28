#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int front,rear,size;
    Node **Q;
};

void create(Queue *q,int size){
    q->size=size;
    q->Q=(Node **)malloc(q->size*sizeof(Node *));
    q->front=q->rear=0;
}                                    
void enqueue(Queue *q,Node* ele){
    if((q->rear+1)%q->size==q->front){
        cout<<"\n\n\n\t\t\tQueue is full.";
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=ele;
    }
}

Node* dequeu(Queue *q){
   Node* x=nullptr;
   if(q->front==q->rear){
     cout<<"\n\n\n\t\t\tQueue is empty.";
   }else{
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
   }
   return x;
}

bool isEmpty(struct Queue *q){
    return q->front==q->rear;
}