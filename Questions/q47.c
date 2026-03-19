/*
Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
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

// Function to calculate height
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Build tree using user input (level order)
struct Node* buildTree() {
    int val;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = newNode(val);

    printf("Enter left child of %d (-1 for NULL): ", val);
    root->left = buildTree();

    printf("Enter right child of %d (-1 for NULL): ", val);
    root->right = buildTree();

    return root;
}

int main() {
    struct Node* root = buildTree();

    int h = height(root);
    printf("Height of Binary Tree: %d\n", h);

    return 0;
}