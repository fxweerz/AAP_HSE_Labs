#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define lmax 50

void input(int c[lmax][lmax], int* n, int* m) {
    int f_err, f_err2;
    char chr;
    do {
        printf("Введите размерность для матрицы, "
            "колличество строк n от 1 до %d, колличество столбцов m от 1 до %d: ", lmax, lmax);
        f_err = scanf("%d%d", n, m);
        f_err2 = 0;
        chr = getchar();
        while(chr!='\n') {
            if ((48 > (int)chr || (int)chr > 57) && (int)chr != 32)
                f_err2 = 1; // Проверка на пробел
            chr = getchar();
        }
        if (*n <= 0 || *m <= 0 || *n > lmax || *m > lmax || f_err != 2 || f_err2 == 1)
            printf("\nОшибка: некорректное значение n или m, попробуйте снова.\n");
    } while (*n <= 0 || *m <= 0 || *n > lmax || *m > lmax || f_err != 2 || f_err2 == 1);

    printf("\nВведите построчно без пробелов %d элементов матрицы C:\n", (*n)*(*m));
    for(int i = 1; i <= *n; i++) {
        for(int j = 1; j <= *m; j++) {
            do {
                f_err = scanf("%d", &c[i][j]);
                f_err2 = 0;
                chr = getchar();
                while(chr!='\n') {
                    if (48 > (int)chr || (int)chr > 57)
                        f_err2 = (int)chr == 45 ? abs(c[i][j]) == c[i][j] : 1; // Проверка на -
                    char chr1 = chr;
                    chr = getchar();
                }
                if (f_err != 1 || f_err2 == 1)
                    printf("\nОшибка! Введите целое число: \n");
            } while (f_err != 1 || f_err2 == 1);
        }
    }
    printf("\nИсходная матрица C:\n");
    for(int i = 1; i <= *n; i++){
        for(int j = 1; j <= *m; j++)
            printf("%5d", c[i][j]);
        printf("\n");
    }
}

int solve(int c[lmax][lmax], int* n, int* m) {
    int max=0, min=INT_MAX;
    for(int i = 1; i <= *n; i++) {
        for(int j = 1; j < *m; j++) {
            for(int k = j + 1; k <= *m; k++) {
                int diff = abs(c[i][j] - c[i][k]);
                if (diff > max)
                    max = diff;
            }
        }
        if (max < min)
            min = max;
        max = 0;
    }
    return min;
}

void print_result(int v) {
    if (v == 0)
        printf("\nРезультат: в матрице нет разностей между элементами строк.\n");
    else
        printf("\nНаименьшая из максимальных разностей по строкам: %d\n", v);
}

int main() {
    printf("Лабораторная работа №3 Леонтьев Сергей БИТ251\n");
    printf("Задание №2 (1)\n");
    int c[lmax][lmax], n, m, v;
    input(c, &n, &m);
    v = solve(c, &n, &m);
    print_result(v);
    return 0;
}