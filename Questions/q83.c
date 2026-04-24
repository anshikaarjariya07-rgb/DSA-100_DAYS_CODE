/*
Problem: Implement Selection Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;
    }

    // Output sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}