/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph
void addEdge(struct Node* adj[], int u, int v) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Add u to v's list (undirected graph)
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Print graph
void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create adjacency list
    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printGraph(adj, n);

    return 0;
}