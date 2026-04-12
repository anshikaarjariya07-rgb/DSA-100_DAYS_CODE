/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int table[SIZE];

void initialize(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
}

int hash(int key, int i, int m) {
    return (key % m + i * i) % m;
}

void insert(int key, int m) {
    int i = 0;
    while (i < m) {
        int idx = hash(key, i, m);
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int search(int key, int m) {
    int i = 0;
    while (i < m) {
        int idx = hash(key, i, m);
        
        if (table[idx] == -1) {
            return 0; // NOT FOUND
        }
        
        if (table[idx] == key) {
            return 1; // FOUND
        }
        
        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    initialize(m);

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}