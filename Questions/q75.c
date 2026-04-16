/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // hashmap using arrays (simple implementation)
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;   // -2 means not visited

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (hash[sum + MAX] != -2) {
            int len = i - hash[sum + MAX];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + MAX] = i;
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));
    return 0;
}