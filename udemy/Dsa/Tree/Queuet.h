#include <iostream>
#include <stdio.h>

using namespace std;

template <class t>
class Queue{

    private :
        int front,rear;
        int size;
        t *ele;

    public :

        Queue(int size){
            this.size=size;
            front=0;
            rear=0;
        }
        void enqueu(Queue &q,t *ele){
            if((front+1)%q.size==rear){
                printf("\n\n\t\tQueue is full.");
            }{
                ele[(front+1)%t.size]=ele;
                front=(front+1)%t.size;
            }
        }

        t dequeue(Queue &q){
            t x;
            if(front==rear){
                print("Queue is empty");
            }else{
                x=ele[(rear+1)%q.size];
                rear=(rear+1)%q.size;
            }
            return x;
        }

}