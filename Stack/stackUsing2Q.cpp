//implement stack using 2 queue

#include <iostream>
#include <stdlib.h>


using namespace std;
struct Queue{
    int front;
    int rear;
    int capacity;
    int *arr;

};


int isFull(Queue *q){
    return ((q->rear+1)%q->capacity==q->front);
}

int isEmpty(Queue *q){

    return q->front==-1;
}

void push(Queue *q,int data){
    if(!isFull(q)){
 
        //chk if the first element is going to be inserted
 
        if(isEmpty(q)){
            q->front=0;
        }
 
 
        q->rear=(q->rear+1)%q->capacity;
 
        q->arr[q->rear]=data;
 
    }
}
 
int removeFront(Queue *q){
    if(!isEmpty(q)){
 
        int result=q->arr[q->front];
        if(q->front==q->rear){
            q->front=q->rear=-1;
 
        }
 
        else{
            //increase the front of the queue
            q->front=(q->front+1)%q->capacity;
        }
 
        return result;
 
    }
 
 
    return -1;
}
int pop(Queue *q1,Queue *q2){
    //move all the items fro the queue 1 to queue 2 untill there is 1 element left
    while (!(q1->front==q1->rear))
    {
        push(q2,removeFront(q1));
    }
    //store and return the element from the queue 1
    int res=removeFront(q1);
 
 
    while (!isEmpty(q2)) {
        push(q1, removeFront(q2));
    }
    return res;  //return the popped itm
 }

int main(){
 //initialization
 
    Queue *q1=new Queue;
    Queue *q2=new Queue;
    q1->front=q1->rear=-1;
    q2->front=q2->rear=-1;
    q1->capacity=q2->capacity=10;
    q1->arr=(int *)malloc(q1->capacity*sizeof(int));
    q2->arr=(int *)malloc(q2->capacity*sizeof(int));



    push(q1,10);
    push(q1,20);
    push(q1,30);
 
    cout<<pop(q1,q2)<<endl;
    cout<<pop(q1,q2)<<endl;
 
    cout<<pop(q1,q2)<<endl;
    cout<<pop(q1,q2)<<endl;
    push(q1,10);
    push(q1,20);
    cout<<pop(q1,q2)<<endl;
    cout<<pop(q1,q2)<<endl;
   //free the allocated memory
    delete[] q1->arr;
    delete[] q2->arr;
    delete q1;
    delete q2;

    return 0;
}