#include <stdio.h>
#include <locale.h>

#define LMAX 100

int first_digit(int num) {
    while(num >= 10)
        num /= 10;
    return num;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int n, z, k, f_err;
    unsigned short f_err2;
    char chr;
    
    printf("Лабораторная работа №2 Леонтьев Сергей БИТ251\n");
    printf("Задание №2 (9)\n");
    
    do {
        printf("Введите колличество элементов n для массива A от 1 до %d: ", LMAX);
        f_err = scanf("%d", &n);
        f_err2 = 0;
        chr = getchar();
        while(chr!='\n') {
            if (48 > (int)chr || (int)chr > 57)
                f_err2 = 1;
            chr = getchar();
        }
        if (n <= 0 || n >= LMAX || f_err != 1 || f_err2 == 1)
            printf("\nОшибка: некорректное значение n, попробуйте снова.\n");
    } while (n <= 0 || n >= LMAX || f_err != 1 || f_err2 == 1);

    int A[n];
    printf("\nВведите построчно без пробелов %d элементов массива A:\n", n);
    for(int i = 0; i < n; i++) {
        do {
            f_err = scanf("%d", &A[i]);
            f_err2 = 0;
            chr = getchar();
            if (A[i] <= 0)
                f_err2 = 1;
            else{
                while(chr!='\n') {
                    if (48 > (int)chr || (int)chr > 57)
                        f_err2 = 1;
                    chr = getchar();
                }
            }
            if (f_err != 1 || f_err2 == 1)
                printf("\nОшибка! Введите целое положительное число : \n");
        } while (f_err != 1 || f_err2 == 1);
    }
    
    printf("\nИсходный массив:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    int B[n];
    k = 0;

    do {
        printf("\nВведите цифру z: ");
        f_err = scanf("%d", &z);
        f_err2 = 0;
        chr = getchar();
        while(chr!='\n') {
            if (48 > (int)chr || (int)chr > 57)
                f_err2 = 1;
            chr = getchar();
        }
        if (z < 0 || z > 9 || f_err != 1 || f_err2 == 1)
            printf("\nОшибка: некорректное значение z, попробуйте снова.");
    } while (z < 0 || z > 9 || f_err != 1 || f_err2 == 1);

    for(int i = 0; i < n; i++){
        if (z == first_digit(A[i]))
            B[k++] = A[i];
    }

    if(k == n) {
        printf("Все числа массива начинаются с цифры z.\n");
    }else if(k > 0) {
        printf("\nСформированный массив B из %d элементов:\n", k);
        for(int i = 0; i < k; i++) {
            printf("%d ", B[i]);
        }
    }else {
        printf("Нет чисел начинающихся с цифры z.\n");
    }
    
    return 0;
}