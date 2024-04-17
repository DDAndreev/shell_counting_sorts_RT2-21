#include <limits.h>
void shell_sort(int *array, int size){ // array - указатель на массив size - количество элементов в массиве
    for (int s = size / 2; s > 0; s /= 2){
        for (int i = s; i < size; i++){
            for (int j = i - s; j >= 0 && array[j] > array[j+s]; j -= s){
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}

void counting_sort(int *array, int size){ // array - указатель на массив size - количество элементов в массиве
    int mn = INT_MAX, mx = INT_MIN;

    for(int i = 0; i < size; i++){
            int x = array[i];
            mn = (x < mn) ? x: mn;
            mx = (x > mx) ? x: mx;
    }

    int *count = calloc(mx-mn + 1, sizeof(int));
    for(int i = 0;i < size; i++){
        count[array[i] - mn] += 1;
    }

    for(int i = 0;i < mx-mn+1; i++){
        for(int j = 0;j < count[i]; j++){
            *array++ = i + mn;
        }
    }
}

