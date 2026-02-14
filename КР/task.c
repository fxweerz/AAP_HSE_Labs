/*Даны целочисленная матрица С[0:N-1,0:M-1]
     и целочисленный массив D[0:K-1].
      Написать программу, которая сортирует по возрастанию
       методом установки элементы тех строк матрицы С, все элементы 
       которых отсутствуют в массиве D. Вычисления оформить в виде функции
        с параметрами.*/

#include <stdio.h>
#include <stdlib.h>
#define lmax 50

void input_matrix(int c[lmax][lmax], int* n, int* m){
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
                f_err2 = 1;
            chr = getchar();
        }
        if (*n <= 0 || *m <= 0 || *n > lmax || *m > lmax || f_err != 2 || f_err2 == 1)
            printf("\nОшибка: некорректное значение n или m, попробуйте снова.\n");
    } while (*n <= 0 || *m <= 0 || *n > lmax || *m > lmax || f_err != 2 || f_err2 == 1);

    printf("\nВведите построчно без пробелов %d элементов матрицы C:\n", (*n)*(*m));
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *m; j++) {
            do {
                f_err = scanf("%d", &c[i][j]);
                f_err2 = 0;
                chr = getchar();
                while(chr!='\n') {
                    if (48 > (int)chr || (int)chr > 57)
                        f_err2 = (int)chr == 45 ? abs(c[i][j]) == c[i][j] : 1;
                    char chr1 = chr;
                    chr = getchar();
                }
                if (f_err != 1 || f_err2 == 1)
                    printf("\nОшибка! Введите целое число: \n");
            } while (f_err != 1 || f_err2 == 1);
        }
    }
    printf("\nИсходная матрица C:\n");
    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++)
            printf("%5d", c[i][j]);
        printf("\n");
    }
}

void input_array(int a[lmax], int* k){
    int f_err, f_err2;
    char chr;
    do {
        printf("Введите количество элементов массива от 1 до %d: ", lmax);
        f_err = scanf("%d", k);
        f_err2 = 0;
        chr = getchar();
        while(chr!='\n') {
            if ((48 > (int)chr || (int)chr > 57) && (int)chr != 32)
                f_err2 = 1; 
            chr = getchar();
        }
        if (*k <= 0 || *k > lmax || f_err != 1 || f_err2 == 1)
            printf("\nОшибка: некорректное значение k, попробуйте снова.\n");
    } while (*k <= 0 || *k > lmax || f_err != 1 || f_err2 == 1);

    printf("\nВведите %d элементов массива A:\n", *k);
    for(int i = 0; i < *k; i++) {
        do {
            f_err = scanf("%d", &a[i]);
            f_err2 = 0;
            chr = getchar();
            while(chr!='\n') {
                if (48 > (int)chr || (int)chr > 57)
                    f_err2 = (int)chr == 45 ? abs(a[i]) == a[i] : 1;
                char chr1 = chr;
                chr = getchar();
            }
            if (f_err != 1 || f_err2 == 1)
                printf("\nОшибка! Введите целое число: \n");
        } while (f_err != 1 || f_err2 == 1);
    }
}


void insertion_sort(int *row, int M) {
    for (int i = 1; i < M; i++) {
        int key = row[i];
        int j = i - 1;
        while (j >= 0 && row[j] > key) {
            row[j + 1] = row[j];
            j--;
        }
        row[j + 1] = key;
    }
}

int sort_matrix(int c[lmax][lmax], int n, int m, int k, int d[lmax]){
    int f = 0;
    for(int i = 0; i < n; i++) {
        int flag = 1;
        for(int j = 0; j < m; j++) {
            if (flag == 0) break;
            for(int i1 = 0; i1 < k; i1++){
                if (c[i][j] == d[i1]){
                    flag = 0;
                    break;
                }
            }
        }
        if (flag){
            insertion_sort(c[i], m);
            f++;
        }
    }
    return f;
}

void print_result(int c[lmax][lmax], int n, int m, int f){
    if (f == 0){
        printf("\nОшибка! Нет строк, подходящих под условие \n");
    } else {
        printf("\nМатрица C, после сортировки:\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                printf("%5d", c[i][j]);
            printf("\n");
        }
    }
}

int main(){
    int c[lmax][lmax], n, m, d[lmax], k;
    input_matrix(c, &n, &m);
    input_array(d, &k);
    int f = sort_matrix(c, n, m, k, d);
    printf("%d", f);
    print_result(c, n, m, f);
    return 0;
}