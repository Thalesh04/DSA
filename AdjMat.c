#include <stdio.h>
#define V 5

// Add edge to adjacency matrix
void addEdge(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

// Display adjacency matrix
void displayMat(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

// BFS traversal
void BFS(int graph[V][V], int start) {
    int visited[V] = {0}, queue[V], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFSUtil(int graph[V][V], int u, int visited[]) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < V; v++) {
        if (graph[u][v] && !visited[v])
            DFSUtil(graph, v, visited);
    }
}
void DFS(int graph[V][V], int start) {
    int visited[V] = {0};
    DFSUtil(graph, start, visited);
    printf("\n");
}

// Main function to test graph
int main() {
    int graph[V][V] = {0};
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency Matrix:\n");
    displayMat(graph);

    printf("BFS starting from 0: ");
    BFS(graph, 0);

    printf("DFS starting from 0: ");
    DFS(graph, 0);

    return 0;
}