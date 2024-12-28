#include <stdio.h>
#include <stdlib.h>

struct Queue1
{
    int front,rear,size;
    int *ele;
};

void createQueue(struct Queue1 *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->ele=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue1 *q,int x){
    printf("\n\n\t\tThe value of front is %d and rear %d before enquing.",q->front,q->rear);
    if(q->rear+1==q->size){
        printf("\n\n\n\t\t\t___________Queue is full ___________________");
        return;
    }
    q->ele[++q->rear]=x;
    printf("\n\n\t\tThe value of front is %d and rear %d after enquing.",q->front,q->rear);
}

int dequeue(struct Queue1 *q){
    printf("\n\n\t\tThe value of front is %d and rear %d before dequeuing.",q->front,q->rear);
    if(q->front==q->rear){
        printf("\n\n\t\t\t____________Queue is empty_________________");
        return -1;
    }
    return q->ele[++q->front];
    printf("\n\n\t\tThe value of front is %d and rear %d after dequing.",q->front,q->rear);
}

void display(struct Queue1 *q){
    int front=q->front,rear=q->rear;
    while(front!=rear){
        printf("\t%d",q->ele[front++]);
    }
}

int main(){
    struct Queue1 q;
    int x,size;
    do{
        printf("\n\n\n\t\t\tEnter : \n\n\t\t\t 1 ------> For creating queue.\n\n\t\t\t 2 ------> For enqueuing element.\n\n\t\t\t 3 ------> For dequeuing element.\n\n\t\t\t 4 ------> For displaying queue element.\n\n\t\t\t 5 ------> For Exiting the program.\n\n\t\t\t\tEnter you choice : ");
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("\n\n\t\t\t\t\tEnter the size of the queue : ");
                scanf("%d",&size);
                createQueue(&q,size);
                break;
            case 2:
                printf("\n\n\t\t\t\t\tEnter the element for enqueing : ");
                scanf("%d",&size);
                enqueue(&q,size);
                break;
            case 3:
                dequeue(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("\n\n\n\t\t\t--------------Exiting the program----------------");
                break;
            default:
                printf("\n\n\n\t\tEnter a valid choice.");
                break;
        }
    }while(x!=5); 
    return 0;
}