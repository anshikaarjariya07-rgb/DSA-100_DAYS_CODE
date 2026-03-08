/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. 
Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>

#define MAX 100

int main()
{
    int queue[MAX];
    int n, m;
    int front = 0, rear = -1, size;

    scanf("%d", &n);
    size = n;

    // Enqueue elements
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % size;
        queue[rear] = x;
    }

    // Number of dequeue operations
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        front = (front + 1) % size;
    }

    // Display queue
    int i = front;
    int count = 0;

    while(count < size)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
        count++;
    }

    return 0;
}