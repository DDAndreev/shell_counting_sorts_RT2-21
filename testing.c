#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <limits.h>
void shell_sort(int* array, int size) { // array - указатель на массив size - количество элементов в массиве
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; i++) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}
void counting_sort(int* array, int size) { // array - указатель на массив size - количество элементов в массиве
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < size; i++) {
        int x = array[i];
        mn = (x < mn) ? x : mn;
        mx = (x > mx) ? x : mx;
    }
    int* count = calloc(mx - mn + 1, sizeof(int));
    for (int i = 0;i < size; i++) {
        count[array[i] - mn] += 1;
    }
    for (int i = 0;i < mx - mn + 1; i++) {
        for (int j = 0;j < count[i]; j++) {
            *array++ = i + mn;
        }
    }
}
int main() {
    int* mass; //указатель на массив
    int time = 0;
    int n = 0;
    int range = 0;
    FILE* file;
    file = fopen("result.txt", "w"); //открываем файл
    for (n = 1; time < 60 ; n++) {
        range = n*50000000;
        mass = (int*)malloc(range * sizeof(int)); //динамическая генеарция массива
        for (int k = 0; k < range; k++) {
            mass[k] = rand() % 1001; //генерируем элементы массива с диапозоном 1000
        }
        clock_t start = clock(); //засекаем время выполения алгоритма
        counting_sort(mass, range, 0, 1000); //counting_sort для сортировки подсчётом
        clock_t end = clock(); //фиксируем время выполнения
        time = (int)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%d %d\n", range, time); //выводим результаты в файл result.txt
        printf("%d  %d\n", range, time);
        free(mass); //освобождаем строку
    }
    fclose(file);
}
