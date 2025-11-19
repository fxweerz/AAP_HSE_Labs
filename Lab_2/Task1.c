#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NMAX 100
#define MMAX 100

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int A[NMAX][MMAX], n, m, k, f_err;
    unsigned short f_err2, has_zero;
    char chr;
    
    printf("Лабораторная работа №2 Леонтьев Сергей БИТ251\n");
    printf("Задание №1 (2)\n");
    
    do {
        printf("Введите размерность для матрицы, "
            "колличество строк n от 1 до %d, колличество столбцов m от 1 до %d: ", NMAX, MMAX);
        f_err = scanf("%d%d", &n, &m);
        f_err2 = 0;
        chr = getchar();
        while(chr!='\n') {
            if ((48 > (int)chr || (int)chr > 57) && (int)chr != 32)
                f_err2 = 1; // Проверка на пробел
            chr = getchar();
        }
        if (n <= 0 || m <= 0 || n > NMAX || m > MMAX || f_err != 2 || f_err2 == 1)
            printf("\nОшибка: некорректное значение n или m, попробуйте снова.\n");
    } while (n <= 0 || m <= 0 || n > NMAX || m > MMAX || f_err != 2 || f_err2 == 1);

    printf("\nВведите построчно без пробелов %d элементов матрицы A:\n", n*m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            do {
                f_err = scanf("%d", &A[i][j]);
                f_err2 = 0;
                chr = getchar();
                while(chr!='\n') {
                    if (48 > (int)chr || (int)chr > 57)
                        f_err2 = (int)chr == 45 ? abs(A[i][j]) == A[i][j] : 1; // Проверка на -
                    char chr1 = chr;
                    chr = getchar();
                }
                if (f_err != 1 || f_err2 == 1)
                    printf("\nОшибка! Введите целое число: \n");
            } while (f_err != 1 || f_err2 == 1);
        }
    }
    
    printf("\nИсходная матрица:\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%5d", A[i][j]);
        printf("\n");
    }

    k = 0;
    for(int i = 1; i <= m; i++){
        has_zero = 0;
        for(int j = 1; j <= n; j++)
            if (A[j][i] == 0)
                has_zero = 1; break;
        if (has_zero) {
            k++;
            for(int j = 1; j <= n; j++)
                A[j][k] = A[j][i];
        }
    }

    if(k > 0 && k != m) {
        printf("\nРезультат после удаления столбцов без нулей:\n");
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++)
                printf("%5d", A[i][j]);
            printf("\n");
        }
    } else if(k == m)
        printf("\nВсе столбцы содержат ноль.\n");
    else 
        printf("\nВсе столбцы были удалены.\n");
    
    return 0;
}