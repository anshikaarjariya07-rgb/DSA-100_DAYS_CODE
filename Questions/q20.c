/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. 
For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: 
[1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. 
Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100003   // Size of hash table (prime number)

typedef struct Node {
    long long key;        // prefix sum
    long long count;      // frequency of this prefix sum
    struct Node* next;
} Node;

Node* hashTable[SIZE];

// Hash function
int hash(long long key) {
    if (key < 0)
        key = -key;
    return key % SIZE;
}

// Insert or update prefix sum in hash table
long long insertOrCount(long long prefix) {
    int index = hash(prefix);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == prefix) {
            temp->count++;
            return temp->count - 1;  // previous count (for result addition)
        }
        temp = temp->next;
    }

    // Not found → create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = prefix;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long prefix_sum = 0;
    long long result = 0;

    // Important: prefix sum 0 appears once initially
    insertOrCount(0);

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        result += insertOrCount(prefix_sum);
    }

    printf("%lld\n", result);

    return 0;
}