#include <stdio.h>
#include <locale.h>
#include <math.h>

#define lmax 200

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n, k, f_err;
    float x, h, a, R[lmax+1];

    printf("Лабораторная работа №1 Леонтьев Сергей БИТ251\n");
    printf("Задание №1 (5)\n");
    // Задание 1
    do {
        printf("Введите длину массива R от 1 до %d: ", lmax);
        f_err = scanf("%d", &n);
        while(getchar()!='\n'); 
        if (n <= 0 || n > lmax || f_err != 1)
            printf("\nОшибка: некорректное значение n, попробуйте снова.\n");
    } while (n <= 0 || n > lmax || f_err != 1);
    printf("Введите x, h, a: ");
    scanf("%f %f %f", &x, &h, &a);
    for (int i = 1; i <= n; i++)
        R[i] = cos(i*h) - cos(a*x + a*h);
    printf("Массив R из %d элементов:\n", n);
    for (int i = 1; i <= n; i++)
        printf("%8.3f ", R[i]);
    printf("\n");

    // Задание 2
    printf("\nЗадание №2 (1)");
    k = 0;
    for (int i = 1; i <= n; i++) {
        if (fabs(R[i]) >= 0.7) {
            k++;
            R[k] = R[i];
        }
    }
    if (k >= 1 && k != n) {
        printf("\nМассив R из %d элементов после удаления:\n", k);
        for (int i = 1; i <= k; i++)
            printf("%8.3f ", R[i]);
        printf("\n");
    } else {
        if (k == 0)
            printf("\nМассив после удаления элементов является пустым.\n");
        else
            printf("\nМассив соответствует исходному, нет элементов подлежащих удалению.\n");
    }

    // Задание 3
    printf("\nЗадание №3 (9)");
    int pos = -1;
    double ma = INFINITY;
    for (int i = 1; i <= k; i++) {
        if (R[i] < 0 && fabs(R[i]) < ma) {
            ma = fabs(R[i]);
            pos = i;
        }
    }
    if (pos == -1) {
        printf("\nРезультат: в массиве нет отрицательных элементов.\n");
    } else if (pos == 1) {
        printf("\nРезультат: до минимального по модулю отрицательного элемента нет чисел.\n");
    } else {
        float sr = 0.0;
        for (int i = 1; i < pos; i++)
            sr += R[i];
        sr /= --pos;
        printf("\nСреднее арифметическое элементов до минимального по модулю отрицательного = %8.3f\n", sr);
    }
    return 0;
}
