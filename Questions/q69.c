//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#define MAX 1000
#define INF 1000000000

// Min Heap structure
struct Node {
    int v, dist;
};

struct MinHeap {
    struct Node heap[MAX];
    int size;
};

// Swap
void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap *h, int i) {
    while (i > 0 && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(struct MinHeap *h, int v, int dist) {
    h->heap[h->size].v = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Pop from heap
struct Node pop(struct MinHeap *h) {
    struct Node root = h->heap[0];
    h->size--;
    h->heap[0] = h->heap[h->size];
    heapifyDown(h, 0);
    return root;
}

// Dijkstra function
void dijkstra(int V, int adj[MAX][MAX], int src) {
    int dist[MAX];
    struct MinHeap h;
    h.size = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        struct Node curr = pop(&h);
        int u = curr.v;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0) {  // edge exists
                int wt = adj[u][v];

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    push(&h, v, dist[v]);
                }
            }
        }
    }

    // Print result
    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
}