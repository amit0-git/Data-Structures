#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *inorderPredecessor(Node *root, int p){
    //function to find the inorder predecessor of the BST
    //left node ka right

    Node *prede=NULL;
    while(root!=NULL){

        if (p<=root->data){
            root=root->left;
        }

        else{
            prede=root;
            root=root->right;
        }

    }
    return prede;
}

Node *inorderSuccessor(Node *root)
{

    //function for finding the inorder successor the BST
    //right ka left
    Node *parent=root;
    Node *successor = root->right;
    while(successor->left!=NULL){
        parent=successor;
        successor=successor->left;
    }

   
    return successor;
}




Node *newNode(int item)
{

    // function for creating new node
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


// insert in the BST
void insert(struct Node *&root, int key)
{
    Node *ptr = newNode(key);
    Node *prev = NULL;
    Node *cur = root;

    while (cur != NULL)
    {
        prev = cur;
        if (key == cur->data)
            return;
        else if (key < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }

    if (prev == NULL)
    {
        // if the bst is empty
        root = ptr;
    }
    else if (key < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
}



void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}



bool isBST(Node *root){


    isBST(root->left);
    isBST(root->right);

}
//delete a node from the BST
Node *deleteNode(Node *root,int key){


    if (root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }

    else{
        if (root->left==NULL){
            return root->right;
        }
        else if (root->right==NULL){
            return root->left;
        }

        //IF THERE ARE VALUES ON BOTH SIDE OF THE NODE
        Node *succ= inorderSuccessor(root);
        root->data=succ->data;
        root->right=deleteNode(root->right,root->data);
    }

    return root;
}
int main()
{

    // root node
    Node *root = NULL;

    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);


   
   

    inOrder(root);

    return 0;
}