// implementation of the graph using the adjancy list using linked list in cpp nd C

#include <iostream>
#include <stdlib.h>

using namespace std;

// struct of node
struct Node
{
    int data;
    Node *next;
};

// structure of Graph
struct Graph
{
    int numVertices;
    Node **adjList;
};

// function to create and return the node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to initialize the graph

Graph *initGraph(int vertices)
{

    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (Node **)malloc(graph->numVertices * sizeof(Node *));

    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// function to add edge in the graph

void addEdge(Graph *graph, int s, int d)
{
    // create a node to add in the source and the destinaton

    // add edge from s to d

    // add vertex in the front of the LL
    Node *node = createNode(d);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;

    // add edge from the destination to the  source
    node = createNode(s);
    node->next = graph->adjList[d];
    graph->adjList[d] = node;
}

void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjList[i];
        while (temp)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);
}

// Print the graph
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *tmp = graph->adjList[i];
        cout << i << ": ";
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }

        cout << endl;
    }
}

// function to implement the BFS algorithm

int *BFS(Graph *graph, int startVertex)
{
    // create the visited array
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    int *level = (int *)malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = 0;
        level[i] = 0;
    }
    // create a queue for level order traversal
    int *queue = (int *)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // enqueue the current node and  mark as the visited node
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    // now perform below operations until queue becomes empty
    cout << "BFS: ";
    while (front < rear)
    {
        // dequeue the current node and process it or print it
        int node = queue[front++];
        cout << node << " ";

        // visit its all the neighbours and enqueue and mark them those are unvisited
        struct Node *tmp = graph->adjList[node];

        while (tmp)
        {
            // enqueue and mark unvisited
            if (!visited[tmp->data])
            {

                queue[rear++] = tmp->data;
                visited[tmp->data] = 1;
                // update the level array
                level[tmp->data] = level[node] + 1;
            }
            // move to next node
            tmp = tmp->next;
        }
    }

    // free the dynamic memory
    free(visited);
    free(queue);

    return level;
}

int main()
{

    Graph *graph = initGraph(5);
    // create graph

    // now add the bw the vertex

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    // addEdge(graph,0,3);
    addEdge(graph, 1, 3);
    // addEdge(graph,2,3);

    int *lvl = BFS(graph, 0);
    cout << endl;
    for (int i = 0; i < graph->numVertices; i++)
    {
        cout << i << " : " << lvl[i] << endl;
    }

    // printGraph(graph);
    freeGraph(graph);
    free(lvl);

    return 0;
}