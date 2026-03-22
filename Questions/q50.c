/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// BST Node
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

// Insert (to build BST)
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Search in BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0; // Not found

    if (root->data == key)
        return 1; // Found

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Main function
int main() {
    struct Node* root = NULL;

    // Build BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 40;

    if (search(root, key))
        printf("Element %d found in BST\n", key);
    else
        printf("Element %d not found in BST\n", key);

    return 0;
}