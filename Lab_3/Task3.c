#include <stdio.h>

#define lmax 200

void input(float a[lmax], int* n) {
    int f_err, f_err2;
    char chr;
    do {
        printf("Введите длину массива A от 1 до %d: ", lmax);
        f_err = scanf("%d", n);
        f_err2 = 0;
        chr = getchar();
        while(chr != '\n') {
            if ((48 > (int)chr || (int)chr > 57))
                f_err2 = 1;
            chr = getchar();
        }
        if (*n <= 0 || *n > lmax || f_err != 1 || f_err2 == 1)
            printf("\nОшибка: некорректное значение n, попробуйте снова.\n");
    } while (*n <= 0 || *n > lmax || f_err != 1 || f_err2 == 1);

    printf("Введите %d элементов массива A построчно без пробелов:\n", *n);
    for (int i = 0; i < *n; i++) {
        do {
                f_err = scanf("%f", &a[i]);
                f_err2 = 0;
                chr = getchar();
                while(chr!='\n') {
                    if ((48 > (int)chr || (int)chr > 57) && (int)chr != 45 && (int)chr != 46)
                        f_err2 = 1;
                    chr = getchar();
                }
                if (f_err != 1 || f_err2 == 1)
                    printf("\nОшибка! Введите число: \n");
            } while (f_err != 1 || f_err2 == 1);
    }

    printf("Исходный массив A из %d элементов:\n", *n);
    for (int i = 0; i < *n; i++)
        printf("%.2f ", a[i]);
    printf("\n");
}

void solve(float a[lmax], int n, float *b, int* k) {
    *k = 0;
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (a[i] == a[j]) {
                int flag = 1;
                for(int p = 0; p < *k; p++){
                    if (b[p] == a[i]){
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    b[*k] = a[i];
                    (*k)++;
                }
                break;
            }
        }
    }
}

void print_result(float b[lmax], int k) {
    if (k > 0) {
        printf("Массив B из %d элементов, содержащий повторяющиеся элементы массива A:\n", k);
        for (int i = 0; i < k; i++)
            printf("%.2f ", b[i]);
        printf("\n");
    } else {
        printf("В массиве A нет повторяющихся элементов.\n");
    }
}

int main() {
    int n, k;
    float a[lmax], b[lmax];
    printf("Лабораторная работа №3 Леонтьев Сергей БИТ251\n");
    printf("Задание №3 (5)\n");
    input(a, &n);
    solve(a, n, b, &k);
    print_result(b, k);
    return 0;
}