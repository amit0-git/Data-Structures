#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *head = NULL;

Node *createNode(int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

// fn for the right view of the tree
// just print the last element of each level

void rightView(Node *root, int level, vector<int> &result)
{

    if (root == NULL)
    {
        return;
    }

    if (result.size() == level)
    {
        result.push_back(root->data);
    }

    // first traverse right then left

    rightView(root->right, level + 1, result);
    rightView(root->left, level + 1, result);
}

// fn to get the left view of  the tree

void leftView(Node *root, int level, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    if (result.size() == level)
    {
        result.push_back(root->data);
    }
    // first traverse right then left
    leftView(root->left, level + 1, result);
    leftView(root->right, level + 1, result);
}

int main()
{

    head = createNode(10);
    head->left = createNode(20);
    head->right = createNode(30);

    head->left->left = createNode(40);
    head->left->right = createNode(50);

    head->right->left = createNode(60);
    head->right->right = createNode(70);

    vector<int> result;
    leftView(head, 0, result);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}