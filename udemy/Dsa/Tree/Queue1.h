#include <iostream>

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

class Queue{

    int front,rear,size;
    Node **ele;

    public:
        Queue(){
            this->size=100;
            front=rear=0;
            ele=new Node*[this->size];
        }

        Queue(int size){
            this->size=size;
            front=rear=0;
            ele=new Node*[this->size];
        }

        void enqueue(Node*);

        Node* dequeue();

        void display();

        bool isEmpty();
};


void Queue::enqueue(Node* p){
    
    if((rear+1)%size == front){
        cout<<"Queue is full";
        return;
    }
    rear=(rear+1)%size;
    ele[rear]=p;
}

Node* Queue::dequeue(){

    if(front==rear){
        cout<<"Empty";
        return nullptr;
    }
    return ele[++front%size];
}

bool Queue::isEmpty(){
    return front==rear;
}

void Queue::display(){
    cout<<"\n\n\t\tThe element of the queue is : ";
    while(!isEmpty()){
        cout<<dequeue()->data<<"\t";
    }
}