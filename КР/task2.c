/*1.	Дана символьная строка. Обращаться к символам по указателю. 
Ввод данных, анализ существования и вывод результата оформить в главной
 функции, вычисления – в отдельной функции с параметрами. 
 Удалить пары латинских букв, расположенных подряд.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define lmax 50

void remove_pairs(char *s) {
    int write = 0;
    for (int read = 0; s[read] != '\0'; read++) {
        if (isalpha(s[read]) && s[read] == s[read + 1]) {
            read++;  
        } else {
            s[write++] = s[read];
        }
    }
    s[write] = '\0';
}

int compare(char *s1, char *s2){
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

int main() {
    int f_err2 = 0;
    char s[lmax];
    printf("Введите строку (макс. длина %d символов): ", lmax - 1);
    do {
        f_err2 = 0;
        if (fgets(s, lmax, stdin) == NULL) {
            f_err2 = 1;
        } else {
            int len = 0;
            while (s[len] != '\0' && s[len] != '\n') len++;

            if (len == lmax - 1 && s[len] != '\n') {
                f_err2 = 1;
                char chr;
                while ((chr = getchar()) != '\n' && chr != EOF);
            }
        }
        if (f_err2 == 1) {
            printf("\nОшибка: некорректная строка или превышена максимальная длина, попробуйте снова.\n");
        }
    } while (f_err2 == 1);

    char new_s[lmax];
    strcpy(new_s, s);
    remove_pairs(new_s);
    int f = compare(s, new_s);
    if (f) {
        printf("Нет удалений, нет пар в изначальной строке\n");
    } else {
        printf("Измененная строка:\n%s", new_s);
    }
    return 0;
}