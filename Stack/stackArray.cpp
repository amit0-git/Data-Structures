//implement stack data structure using array

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stack{
    //implement stack using the array
    int *arr;
    int top;
    int capacity;
};

int isFull(Stack *s){
    //chk whether stack is full
    //check wheteher top=capacity-1
    return (s->top==s->capacity-1);
}

int isEmpty(Stack *s){
    //chk whether stack is empty
    //check wheteher top= -1
    return (s->top==-1);
}

void push(Stack *s,int data){
    //push into the stack
    if(isFull(s)){
        //overflow condition
        return;
    }

    s->arr[++s->top]=data;

}

int pop(Stack *s){
    //pop data from the stack

    if(isEmpty(s)){
        //underflow condition
        return -1;
    }

    return s->arr[s->top--];
}


int peek(Stack *s){

    //get the data of top of stack w/o removing it


    if (!isEmpty(s)){
        return s->arr[s->top];
    }

    return -1;
}
int main(){

    //initialize the stack
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->capacity=10;
    s->top=-1;
    s->arr=(int *)malloc(s->capacity*sizeof(int));

    //perform the operations


    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);


    


    








    return 0;
}