#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <limits.h>
void shell_sort(int* array, int size) { // array - ��������� �� ������ size - ���������� ��������� � �������
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
void counting_sort(int* array, int size) { // array - ��������� �� ������ size - ���������� ��������� � �������
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
    int* mass; //��������� �� ������
    int time = 0;
    int n = 0;
    int range = 0;
    FILE* file;
    file = fopen("result.txt", "w"); //��������� ����
    for (n = 1; time < 60 ; n++) {
        range = n*50000000;
        mass = (int*)malloc(range * sizeof(int)); //������������ ��������� �������
        for (int k = 0; k < range; k++) {
            mass[k] = rand() % 1001; //���������� �������� ������� � ���������� 1000
        }
        clock_t start = clock(); //�������� ����� ��������� ���������
        counting_sort(mass, range, 0, 1000); //counting_sort ��� ���������� ���������
        clock_t end = clock(); //��������� ����� ����������
        time = (int)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%d %d\n", range, time); //������� ���������� � ���� result.txt
        printf("%d  %d\n", range, time);
        free(mass); //����������� ������
    }
    fclose(file);
}
