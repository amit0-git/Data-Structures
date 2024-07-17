//CIRCULAR QUEUE USING ARRAY

#include <iostream>
using namespace std;
#define MAX 5
struct Queue{
    int arr[MAX];
    int front;
    int rear;
};


int isFull(Queue *q){
    //chk if the queue is full
    return ((q->rear+1)%MAX==q->front);
}

int isEmpty(Queue *q){
    //chk if the queue is empty
    
    return (q->front==-1);
}

void enqueue(Queue *q,int data){
    if(isFull(q)){
        return;
    }
    
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear=(q->rear+1)%MAX;
    q->arr[q->rear]=data;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
    
        return -1;
    }
    
    int result=q->arr[q->front];
    //if one element left
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front=(q->front+1)%MAX;
    }
    return result;
    
}

int main() {
    Queue *q=new Queue;
    //initialize the queue
    q->front=q->rear=-1;
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,50);
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;







    
     
    
    
    
    

    return 0;
}