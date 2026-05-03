/*
Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *x = (Car *)a;
    Car *y = (Car *)b;
    return y->pos - x->pos;   // descending by position
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    Car cars[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].pos);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    printf("%d", fleets);

    return 0;
}