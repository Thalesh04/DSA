#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100
#define INF 0 // use 0 to denote no edge for weight graphs
// graph
typedef struct
{
    int V;               // number of vertices
    int directed;        // is the graph directed? 1 - true, 0 - false
    int weighted;        // is the graph weighted? 1 - true, 0 - false
    int adj[MAXV][MAXV]; // adjacency matrix
} Graph;

// create a graph
void initGraph(Graph *g, int V, int directed, int weighted)
{
    g->V = V;
    g->directed = directed;
    g->weighted = weighted;
    int i, j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            g->adj[i][j] = INF; // initialize with no edge
        }
    }
}
// add edge
void addEdge(Graph *g, int u, int v, int weight)
{
    if (u < 0 || u >= g->V || v < 0 || v >= g->V)
    {
        printf("Invalid vertex number\n");
        return;
    }
    int val = g->weighted ? weight : 1;
    g->adj[u][v] = val;
    if (!g->directed)
    {
        g->adj[v][u] = val;
    }
}
// print graph
void printGraph(Graph *g)
{
    int i, j;
    for (i = 0; i < g->V; i++)
    {
        for (j = 0; j < g->V; j++)
        {
            if (g->adj[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", g->adj[i][j]);
        }
        printf("\n");
    }
}
// main method  
int main()
{
    Graph g;
    initGraph(&g, 5, 0, 1); // undirected weighted graph with 5 vertices
    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 4, 20);
    addEdge(&g, 1, 2, 30);
    addEdge(&g, 1, 3, 40);
    addEdge(&g, 1, 4, 50);
    addEdge(&g, 2, 3, 60);
    addEdge(&g, 3, 4, 70);

    printf("Adjacency Matrix:\n");
    printGraph(&g);

    return 0;
}