#include <iostream>

using namespace std;

class Node{
    public : 
        int data;
        Node *lchild,*rchild;
        Node(int data){
            this->data=data;
            lchild=nullptr;
            rchild=nullptr;
        }
};
class Queue{
    private :
        int front,rear,size;
        Node **ele;
    public :
        Queue(int size){
            this->front=this->rear=0;
            this->size=size;
            ele=new Node*[size];
        }
        void enqueue(Node *temp);
        Node* dequeue();
        bool isEmpty();
};

void Queue::enqueue(Node *temp){
    if((rear+1)%size==front)
        cout<<"Queue is full";
    else {
        rear=(rear+1)%size;
        ele[rear]=temp;
    }   
}

Node* Queue::dequeue(){
    if(front==rear){
        cout<<"Queue is empty";
        return nullptr;
    }
    front=(front+1)%size;
    return ele[front];
}

bool Queue::isEmpty(){
    return front==rear;
}