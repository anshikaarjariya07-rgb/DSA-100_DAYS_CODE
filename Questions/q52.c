/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];

        // Left child
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// LCA function
struct Node* LCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = LCA(root, p, q);

    if (lca)
        printf("%d\n", lca->data);

    return 0;
}