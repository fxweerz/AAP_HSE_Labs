#include <stdio.h>

void input(float* a, float* b, float* c, float* d, float* e, float* f) {
    int f_err, f_err2;
    printf("Введите коэффициенты a, b, c, d, e, f через пробел: ");
    do{ 
        f_err = scanf("%f %f %f %f %f %f", a, b, c, d, e, f);
        f_err2 = 0;
        char chr = getchar();
        while(chr!='\n') {
            if ((48 > (int)chr || (int)chr > 57) &&
                (int)chr != 32 && (int)chr != 45 && (int)chr != 46)
                f_err2 = 1;
            chr = getchar();
        }
        if (f_err != 6 || f_err2 == 1 || (*a * *e - *d * *b == 0) || *a == 0)
            printf("\nОшибка: некорректные коэффициенты или происходит деление на 0, попробуйте снова.\n");
    } while (f_err != 6 || f_err2 == 1 || (*a * *e - *d * *b == 0) || *a == 0);
}

void solve(float a, float b, float c, float d, float e, float f, float* x, float* y) {
    *x = (c / a) - ((b * (f - ((d * c) / a))) / (a * (e - ((d * b) / a))));
    *y = (f - ((d * c) / a)) / (e - ((d * b) / a));
}

void print_result(float x, float y) {
    printf("Решение системы уравнений:\nx = %8.3f\ny = %8.3f\n", x, y);
}

int main() {
    printf("Лабораторная работа №3 Леонтьев Сергей БИТ251\n");
    printf("Задание №1 (9)\n");
    float a, b, c, d, e, f, x, y;
    input(&a, &b, &c, &d, &e, &f);
    solve(a, b, c, d, e, f, &x, &y);
    print_result(x, y);
    return 0;
}