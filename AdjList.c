#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100

// adj list node
typedef struct Node
{
    int dest;
    int weight;
    struct Node *next;
} Node;

// Graph Structure
typedef struct
{
    int V;           // number of vertices
    int directed;    // is the graph directed? 1 - true, 0 - false
    int weighted;    // is the graph weighted? 1 - true, 0 - false
    Node *adj[MAXV]; // adjacency list
} Graph;

// Queue for BFS
typedef struct
{
    int items[MAXV];
    int front;
    int rear;
} Queue;

// initialize the queue
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

// check if the queue is empty
int isEmpty(Queue *q)
{
    return q->rear < q->front;
}

// insert element into the queue
void enqueue(Queue *q, int value)
{
    if (q->rear < MAXV - 1)
    {
        q->items[++q->rear] = value;
    }
}

// remove element from the queue
int dequeue(Queue *q)
{
    if (!isEmpty(q))
    {
        return q->items[q->front++];
    }
    return -1; // return -1 if queue is empty
}
// create graph

void initGraph(Graph *g, int V, int directed, int weighted)
{
    g->V = V;
    g->directed = directed;
    g->weighted = weighted;
    int i;
    for (i = 0; i < V; i++)
    {
        g->adj[i] = NULL;
    }
}
// create new adjency list node
Node *createNode(int v, int w)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Graph *g, int u, int v, int weight)
{
    if (u < 0 || u >= g->V || v < 0 || v >= g->V)
    {
        return;
    }
    int val = g->weighted ? weight : 1;
    Node *newNode = createNode(v, val);
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
    if (!g->directed)
    {
        newNode = createNode(u, val);
        newNode->next = g->adj[v];
        g->adj[v] = newNode;
    }
}

// BFS algorithm

void BFS(Graph *g, int start)
{
    int visited[MAXV] = {0};
    Queue q;
    initQueue(&q);
    visited[start] = 1;
    enqueue(&q, start);
    printf("BFS starting from vertex %d:\n", start);
    while (!isEmpty(&q))
    {
        int curr = dequeue(&q);
        printf("Visited %d\n", curr);
        Node *temp = g->adj[curr];
        while (temp)
        {
            int adjVertex = temp->dest;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
int main()
{
    Graph g;
    initGraph(&g, 5, 0, 1);
    addEdge(&g, 0, 1, 2);
    addEdge(&g, 0, 4, 4);
    addEdge(&g, 1, 3, 5);
    addEdge(&g, 2, 4, 2);
    addEdge(&g, 3, 4, 2);

    BFS(&g, 0);
    return 0;
}