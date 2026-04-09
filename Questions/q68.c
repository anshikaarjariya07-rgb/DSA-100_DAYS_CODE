//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

int* topoSort(int V, int** adj, int* adjSize, int* returnSize) {
    int* indegree = (int*)calloc(V, sizeof(int));
    int* result = (int*)malloc(V * sizeof(int));
    int* queue = (int*)malloc(V * sizeof(int));
    
    int front = 0, rear = 0;
    
    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adjSize[i]; j++) {
            indegree[adj[i][j]]++;
        }
    }
    
    // Step 2: Push nodes with indegree 0 into queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int count = 0;
    
    // Step 3: Process queue
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;
        
        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;
            
            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }
    
    *returnSize = count;
    
    // Optional: check for cycle
    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    }
    
    return result;
}