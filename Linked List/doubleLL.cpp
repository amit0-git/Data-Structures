#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

struct Node
{

    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int x, Node *p, Node *n)
    {
        data = x;
        prev = p;
        next = n;
    }

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

// print the DLL

void print(Node *head)
{
    Node *temp = head;
    for (temp = head; temp != nullptr; temp = temp->next)
    {

        cout << temp->data << " ";
    }
    cout << endl;
}

// convetr arr to Dll

Node *convertArr2Dll(const vi &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *prev1 = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev1;

        prev1->next = temp;

        prev1 = temp;
    }

    return head;
}

// delete operations

// 1. delete head

Node *deleteHead(Node *head)
{

    if (head == nullptr)
    {
        // List is empty, nothing to delete
        return nullptr;
    }

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    delete temp; // Free the memory of the old head node
    return head;
}


// 2. delete tail node

Node *deleteTail(Node *head){

    if (head==nullptr){
        return head;
    }
    // if there is one element 

    if (head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node *newTail=temp->prev;
    newTail->next=nullptr;

    delete temp;

    return head;
}

// 3.  delete kth element




int main()
{

    vi v = {1,2,3};
    Node *head = convertArr2Dll(v);
    print(head);

    head = deleteTail(head);
    print(head);

    return 0;
}