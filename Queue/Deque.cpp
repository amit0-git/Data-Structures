//implementation of the Double Ended Queue 
// operations on the deque
// 1. insertFront()
// 2. insertLast()
// 3. deleteFront()
// 4. deleteLast()


#include <iostream>
#include <stdlib.h>


using namespace std;


struct Deque{
    int front ;
    int rear;
    int *arr;
    int capacity;
};





int isFull(Deque *q){
    //chk if the queue is full
    return ((q->rear+1)%q->capacity==q->front);
}

int isEmpty(Deque *q){
    //chk if the queue is empty
    
    return (q->front==-1);
}


void insertFront(Deque *q,int data){

    if(!isFull(q)){

        // case 1 : there are no elements
        // increase the front and rear and add element at arr[front]

        if(isEmpty(q)){
            q->front=q->rear=0;
            q->arr[q->front]=data;
        }

        else{

            q->front=(q->front-1+q->capacity)%q->capacity;
            q->arr[q->front]=data;
        }


    }

}
void insertLast(Deque *q,int data){

    if(!isFull(q)){

        //case 1
        //if the queue is empty

        if(isEmpty(q)){
            q->front=q->rear=0;
            q->arr[q->rear]=data;
        }

        else{
            q->rear=(q->rear+1)%q->capacity;
            q->arr[q->rear]=data;
        }




    }

}

int deleteFront(Deque *q){
    int res=-1;
    if(!isEmpty(q)){

        res=q->arr[q->front];

        //case 1
        // if the queue has only one element left

        if(q->front==q->rear){
            q->front=q->rear=-1;
        }

        else{

            //decrement the front
            q->front=(q->front+1)%q->capacity;

        }
    }


    return res;
}

int deleteRear(Deque *q){
    int res=-1;
    if (!isEmpty(q)){

        res=q->arr[q->rear];

        //case 1
        //if the queue has only one element left

        if(q->front==q->rear){
            q->front=q->rear=-1;
        }

        else{
            //decrement the rear
            q->rear=(q->rear-1+q->capacity)%q->capacity;
        }



    }
}
int main(){
    Deque *q=new Deque;
    q->front=q->rear=-1;
    q->capacity=10;
    q->arr=(int *)malloc(q->capacity*sizeof(int));

    insertFront(q,10);
    insertFront(q,20);
    insertLast(q,50);
    insertFront(q,30);

    cout<<deleteFront(q)<<endl;
    cout<<deleteFront(q)<<endl;
    cout<<deleteFront(q)<<endl;
    cout<<deleteFront(q)<<endl;





    return 0;
}
