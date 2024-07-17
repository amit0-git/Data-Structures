#include <bits/stdc++.h>

using namespace std;

struct Node
{

    int data;
    Node *next;

    // constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// print the linked list

void print(Node *head)
{

    Node *cur = head;
    for (cur = head; cur != nullptr; cur = cur->next)
    {
        cout << cur->data << " ";
    }
}

// function to connvert arr to ll

Node *convertArr2LL(const vector<int> &arr)
{

    if (arr.empty())
    {
        return nullptr;
    }
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *tmp1 = new Node(arr[i]);
        temp->next = tmp1;

        temp = tmp1;
    }
    return head;
}

// delete operations

// 1. delete from the front

Node *deleteHead(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *temp = head;
    head = head->next;

    delete temp;

    return head;
}

// 2. delete the last node
Node *deleteTail(Node *head)
{
    // chk if the head is null or LL only contains one element

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

// 3. delete kth element

Node *deleteK(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    if (k == 1)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;

        return head;
    }
    Node *prev = nullptr;
    Node *cur = head;
    int count = 0;

    while (cur != nullptr)
    {
        count++;

        if (count == k)
        {
            prev->next = cur->next;
            delete cur;

            break;
        }

        prev = cur;
        cur = cur->next;
    }

    return head;
}

// 4. delete particular element

Node *deleteElement(Node *head, int num)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == num)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;

        return head;
    }
    Node *prev = nullptr;
    Node *cur = head;

    while (cur != nullptr)
    {

        if (cur->data == num)
        {
            prev->next = cur->next;
            delete cur;

            break;
        }

        prev = cur;
        cur = cur->next;
    }

    return head;
}

// insertion in the linked list

// 1. in the head

Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);

    return temp;
}

// 2. in the end

Node *insertTail(Node *head, int val)
{

    // if the head is nullptr
    if (head == nullptr)
    {
        return new Node(val);
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;

    return head;
}

// 3. insert at nth position

Node *insertAtPos(Node *head,int val,int pos){

    //if the head  is null
    if (head==nullptr){

        if (pos==1){
            return new Node(val);
        }
        else {
            return head;
        }
    }

    //if the pos is 1
    if (pos==1){

        return new Node(val,head);
    }

    int c=0;
    Node *temp=head;

    while (temp!=nullptr)
    {
        c++;
        //  1 2 3 4 5 
        if (c==(pos-1)){
            Node *newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;

            break;


            
        }

        //increment the next pointer
        temp=temp->next;
    }

    return head;
    

}

int main()
{

    vector<int> arr = {1, 2, 30, 4, 5, 6};
    Node *head = convertArr2LL(arr);
    print(head);

   
    head=insertAtPos(head,50,);
    cout << endl;

    print(head);

    return 0;
}