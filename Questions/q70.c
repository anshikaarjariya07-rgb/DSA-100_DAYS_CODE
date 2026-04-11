//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void bellmanFord(int n, int m, int edges[][3], int src) {
    int dist[n];

    // Step 1: Initialize distances
    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Step 2: Relax edges (n-1 times)
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 4: Print shortest distances
    printf("Shortest distances from source %d:\n", src);
    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

// Example usage
int main() {
    int n = 5, m = 8;

    int edges[8][3] = {
        {0,1,-1}, {0,2,4},
        {1,2,3}, {1,3,2},
        {1,4,2}, {3,2,5},
        {3,1,1}, {4,3,-3}
    };

    int src = 0;

    bellmanFord(n, m, edges, src);

    return 0;
}