#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "sorts.h"

int main() {
    int* mass;
    int time = 0;
    int n = 0;
    int range = 0;
    FILE* file;
    file = fopen("result.txt", "w");
    for (n = 1; time < 60 ; n++) {
        range = n*50000000;
        mass = (int*)malloc(range * sizeof(int));
        for (int k = 0; k < range; k++) {
            mass[k] = rand() % 1001;
        }
        clock_t start = clock();
        counting_sort(mass, range);
        clock_t end = clock();
        time = (int)((end - start) / CLOCKS_PER_SEC);
        fprintf(file, "%d %d\n", range, time);
        printf("%d  %d\n", range, time);
        free(mass);
    }
    fclose(file);
}
