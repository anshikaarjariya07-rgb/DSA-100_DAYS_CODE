/*
Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order construction
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Build tree using level order input
struct Node* buildTree() {
    int val;

    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = newNode(val);
    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();

        // Left child
        printf("Enter left child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &val);
        if (val != -1) {
            temp->left = newNode(val);
            enqueue(temp->left);
        }

        // Right child
        printf("Enter right child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &val);
        if (val != -1) {
            temp->right = newNode(val);
            enqueue(temp->right);
        }
    }

    return root;
}

// Main function
int main() {
    struct Node* root = buildTree();

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}