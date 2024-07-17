//implement stack data structure using Linked List

#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node {
    int data;
    Node *next;
};

void push(Node *&top,int data){
    //add nodes to the beginning of the Linked List
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->data=data;
    
    
    
    tmp->next=top;
    top=tmp;
    
}

int pop(Node *&top){


    if(top==NULL){
        return -1;
    }

    int res=top->data;
    top=top->next;

    return res;
}
int main(){
    Node *top=NULL;

    push(top,10);
    push(top,20);
    push(top,30);


    cout <<pop(top)<<endl;
    cout <<pop(top)<<endl;
    cout <<pop(top)<<endl;
    cout <<pop(top)<<endl;

 


    return 0;
}