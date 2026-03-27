/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure
struct Node* queue[100];
int front = -1, rear = -1;

// Enqueue
void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (i < n) {
        struct Node* current = dequeue();

        // Left child
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }
    return root;
}

// Print Right View
void rightView(struct Node* root) {
    if (root == NULL) return;

    // Reset queue
    front = rear = -1;
    enqueue(root);

    while (front <= rear) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            // If last node of level
            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left)
                enqueue(temp->left);
            if (temp->right)
                enqueue(temp->right);
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}