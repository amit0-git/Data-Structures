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

Node *deleteTail(Node *head)
{

    if (head == nullptr)
    {
        return head;
    }
    // if there is one element

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newTail = temp->prev;
    newTail->next = nullptr;

    delete temp;

    return head;
}

// 3.  delete kth element

//  1 2 3 4 5
Node *deleteKth(Node *head, int pos)
{
    if (head == nullptr)
    {
        return nullptr; // If the list is empty, return nullptr
    }

    int c = 0;
    Node *tmp = head;

    // Traverse to the k-th node
    while (tmp != nullptr)
    {
        c++;
        if (c == pos)
        {
            break;
        }
        tmp = tmp->next;
    }

    // If pos is greater than the length of the list, return head
    if (tmp == nullptr)
    {
        return head;
    }

    Node *back = tmp->prev;
    Node *front = tmp->next;

    // Case 1: If there is only one element
    if (back == nullptr && front == nullptr)
    {
        delete tmp;
        return nullptr;
    }
    // Case 2: Deleting the first element
    else if (back == nullptr)
    {
        head = head->next;
        head->prev = nullptr;
        delete tmp;
        return head;
    }
    // Case 3: Deleting the last element
    else if (front == nullptr)
    {
        back->next = nullptr;
        delete tmp;
        return head;
    }
    // Case 4: Deleting a middle element
    else
    {
        back->next = front;
        front->prev = back;
        delete tmp;
    }

    return head;
}

// 4. delete K node

Node *deleteNode(Node *head, int element)
{

    if (head == nullptr)
    {
        return nullptr;
    }

    Node *tmp = head;
    while (tmp != nullptr)
    {

        if (tmp->data == element)
        {
            break;
        }

        tmp = tmp->next;
    }

    // if the element not found
    if (tmp == nullptr)
    {
        return head;
    }
    // if the node to be deleted is the head node

    if (head == tmp)
    {
        head = tmp->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }
    }

    // if the node to be deleted is not the head node

    else
    {
        tmp->prev->next = tmp->next;

        if (tmp->next != nullptr)
        {
            tmp->next->prev = tmp->prev;
        }
    }
    // delete the temp node
    delete tmp;

    return head;
}
int main()
{

    vi v = {1, 2, 3};
    Node *head = convertArr2Dll(v);
    print(head);

    head = deleteNode(head, 4);
    print(head);

    return 0;
}