#include <iostream>
#include <stdlib.h>


using namespace std;

struct Stack{
    int top;
    int *arr;
    int capacity;
};

int isFull(Stack *s){
    return (s->top==s->capacity-1);
}

int isEmpty(Stack *s){
    return (s->top==-1);
}

void push(Stack *s,int data){
    if(!isFull(s)){
        s->arr[++s->top]=data;

    }

}
int removeTop(Stack *s){
    //fn to remove the top item from the stack

    if (!isEmpty(s)){
        int res=s->arr[s->top--];
        return res;
    }

    return -1;
}

int pop(Stack  *s1,Stack *s2){
    int res=-1;

    //move all the elements of the stack1 to stack2
    while(!isEmpty(s1)){
        push(s2,removeTop(s1));
    }
    //now remove top item of the stack 2
    res=removeTop(s2);

    //now move all the items from the stack2 to stack1
    while(!isEmpty(s2)){
        push(s1,removeTop(s2));
    }


    return res;
    
}
int main(){
//initialize the stack
    Stack *s1=(Stack *)malloc(sizeof(Stack)); // main stack

    Stack *s2=(Stack *)malloc(sizeof(Stack)); //auxiliary stack
    s1->top=s2->top=-1;
    s1->capacity=s2->capacity=10;

    s1->arr=(int *)malloc(s1->capacity*(sizeof(int)));
    s2->arr=(int *)malloc(s2->capacity*(sizeof(int)));

    push(s1,10);
    push(s1,20);
    push(s1,30);
    push(s1,40);

    cout <<pop(s1,s2)<<endl;
    cout <<pop(s1,s2)<<endl;
    cout <<pop(s1,s2)<<endl;
    cout <<pop(s1,s2)<<endl;
    cout <<pop(s1,s2)<<endl;
    push(s1,40);
    cout <<pop(s1,s2)<<endl;



    delete[] s1->arr; // Free allocated memory
    delete[] s2->arr;
    delete s1;
    delete s2;
   



    return 0;
}