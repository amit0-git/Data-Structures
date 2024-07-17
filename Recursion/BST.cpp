#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

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

// fn to find the height of the BST
int BSTheight(Node *root)
{

    // base case

    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    // define only one case rest will be handled by the recursion

    return max(BSTheight(root->left), BSTheight(root->right)) + 1;
}

// fn for level order traversal of the BST
vector<int> levelOrder(Node *root)
{
    // array for storing the result
    vector<int> result;

    queue<Node *> q;

    if (root == NULL)
    {
        return result;
    }

    // push the start element in the queue

    q.push(root);

    // traverse all the neighbours of the queue untill qu becomes empty

    while (!q.empty())
    {
        // pop the element from the queue for processing
        Node *node = q.front();
        q.pop();

        // put the result in the result array
        result.push_back(node->data);

        // enter the left and right child in the queue

        if (node->left)
        {
            q.push(node->left);
        }

        if (node->right)
        {
            q.push(node->right);
        }
    }
    return result;
}


// fn for zig-zag level order traversal

vector<int> zigZagTraverse(Node *root)
{
    vector<int> results;
    queue<Node *> q;

    bool ltr = true;

    if (root == NULL)
    {
        return results;
    }

    // push the start element in the q

    q.push(root);

    while (!q.empty())
    {

        // first take all the nodes of that lvl and perform operation
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            // find index
            int index = (ltr) ? i : (size - i - 1);

            row[index] = node->data;

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }

        //after this level
        ltr=!ltr;

        for (int i=0;i<row.size();i++){
            results.push_back(row[i]);
            }
        
    }


    return results;
}

int main()
{

    head = createNode(10);
    head->left = createNode(20);
    head->right = createNode(30);

    head->left->left = createNode(40);
    head->left->right = createNode(50);

    head->right->left = createNode(60);
    head->right->right= createNode(70);

    vector<int> bfs = zigZagTraverse(head);

    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }

    return 0;
}