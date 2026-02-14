#include <stdio.h>
#include <stdlib.h>

#define nmax 100

void create_file(const char *filename, int *n, double *x, FILE *f){
    int f_err, f_err2;
    if(!(f = fopen("num.txt", "w"))){
        printf("Ошибка открытия файла\n");
        exit(1);
    }
    do{
        printf("Введите колличество чисел от 1 до %d:", nmax);
        f_err = scanf("%d", n);
        f_err2 = 0;
        char chr = getchar();
        while(chr!='\n') {
            if (48 > (int)chr || (int)chr > 57)
                f_err2 = 1;
            chr = getchar();
        }
        if (n <= 0 || *n > nmax || f_err != 1 || f_err2 == 1) {
            printf("\nОшибка: некорректное колличество чисел, попробуйте снова.\n");
        }
    } while (n <= 0 || *n > nmax || f_err != 1 || f_err2 == 1);
    printf("Введите %d действительных чисел:\n", *n);
    for(int j = 0; j < *n; j++) {
        do {
            f_err = scanf("%lf", x);
            f_err2 = 0;
            char chr = getchar();
            while(chr!='\n') {
                if ((48 > (int)chr || (int)chr > 57) && (chr != '.' && chr != '-'))
                    f_err2 = 1;
                char chr1 = chr;
                chr = getchar();
            }
            if (f_err != 1 || f_err2 == 1)
                printf("\nОшибка! Введите действительное число: \n");
        } while (f_err != 1 || f_err2 == 1);
        fprintf(f, "%.2lf\n", *x);
    }
    fclose(f);
}

double solve(FILE *f, double *x){
    int count = 0;
    double sum = 0.0;
    while (fscanf(f, "%lf", x) == 1) {
        if (*x < 0) {
            sum += *x;
            count++;
        }
    }
    return count == 0 ? 0.0 : sum / count;
}

void print_result(double result){
    if (result == 0.0){
        printf("Отрицательных чисел нет\n");
    } else {
        printf("Среднее арифметическое отрицательных: %.2lf\n", result);
    }
}

void read_file(const char *filename, double *x, FILE *f){
    if (!(f = fopen(filename, "r"))){
        printf("Ошибка открытия файла\n");
        exit(1);
    }
    print_result(solve(f, x));
    fclose(f);
}

int main() {
    FILE *f;
    int n;
    double x;
    create_file("num.txt", &n, &x, f);
    read_file("num.txt", &x, f);
    return 0;
}