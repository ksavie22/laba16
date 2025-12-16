#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void task1() {
    double* arr = NULL;
    double* new_arr = NULL;
    int n;

    printf("Размер массива: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(double));
    if (!arr) return;

    for (int i = 0; i < n; i++) {
        printf("Элемент %d: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("\nИсходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    new_arr = malloc(n * sizeof(double));
    if (!new_arr) {
        free(arr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) new_arr[i] = 0;
        else new_arr[i] = arr[i];
    }

    printf("\n\nНовый массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", new_arr[i]);
    }

    free(arr);
    free(new_arr);
}

void task2() {
    double arr[100];
    int i;
    double start = 0.2;
    double end = 2.2;

    for (i = 0; i < 100; i++) {
        double x = start + (end - start) * i / 99.0;
        arr[i] = 1.8 * pow(x, 2) - sin(10 * x);
    }

    double sum_pos = 0, sum_neg = 0;
    int pos = 0, neg = 0;

    for (i = 0; i < 100; i++) {
        if (arr[i] >= 0) {
            sum_pos += arr[i];
            pos++;
        }
        else {
            sum_neg += arr[i];
            neg++;
        }
    }

    printf("\nМассив: arr\n");
    printf("Сумма положительных: %.6f\n", sum_pos);
    printf("Сумма отрицательных: %.6f\n", sum_neg);
    printf("Положительных: %d\n", pos);
    printf("Отрицательных: %d\n", neg);
    if (pos > 0) {
        printf("Среднее положительных: %.6f\n", sum_pos / pos);
    }
    else {
        printf("Положительных элементов нет\n");
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    task1();
    //task2();
    return 0;
}