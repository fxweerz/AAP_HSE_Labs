#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define lmax 51
#define kmax 10

int substring_search(char a[kmax][lmax], char sub[kmax][lmax], int k) {
    int ksub = 0;
    for (int i = 0; i < k; i++) {
        int len = strlen(a[i]);
        for (int j = 0; j < len; j++) {
            if ((a[i][j] >= 'A' && a[i][j] <= 'Z') || (a[i][j] >= 'a' && a[i][j] <= 'z')) {
                for (int j1 = j + 1; j1 < len; j1++) {
                    if ((a[i][j1] >= 'A' && a[i][j1] <= 'Z') || (a[i][j1] >= 'a' && a[i][j1] <= 'z')) {
                        int sub_len = j1 - j - 1;
                        if (sub_len > 0) {
                            char flag[lmax];
                            strncpy(flag, &a[i][j + 1], sub_len);
                            flag[sub_len] = '\0';
                            int exists = 0;
                            for (int m = 0; m < ksub; m++) {
                                if (strcmp(flag, sub[m]) == 0) {
                                    exists = 1;
                                    break;
                                }
                            }
                            if (!exists) {
                                strcpy(sub[ksub], flag);
                                ksub++;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return ksub;
}

void ogr(char sub[kmax][lmax], int ksub, char res[lmax]) {
    res[0] = '\0';
    for (int i = 0; i < ksub; i++) {
        int len = strlen(sub[i]);
        if (len < 2) continue;
        if ((sub[i][0] == '+' || sub[i][0] == '-' || (sub[i][0] >= '*' && sub[i][0] <= '/')) &&
            (sub[i][len - 1] == '+' || sub[i][len - 1] == '-' || (sub[i][len - 1] >= '*' && sub[i][len - 1] <= '/'))) {
            strcpy(res, sub[i]);
            return;
        }
    }
}
void find_old_str(char a[kmax][lmax], int k, char str_old[lmax], char sub[lmax]) {
    str_old[0] = '\0';
    int len_sub = strlen(sub);
    for (int i = 0; i < k; i++) {
        if (strstr(a[i], sub) != NULL) {
            strcpy(str_old, a[i]);
            return;
        }
    }
}

void update_string(char str[lmax], char new_str[lmax]) {
    int idx = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
            new_str[idx++] = str[i];
        }
    }
    new_str[idx] = '\0';
}
int main() {
    setlocale(LC_ALL, "Russian");

    char a[kmax][lmax];
    int k;

    do {
        printf("Введите количество строк от 1 до %d: ", kmax);
        if (scanf("%d", &k) != 1 || k < 1 || k > kmax) {
            printf("Ошибка: некорректное количество строк.\n");
            while (getchar() != '\n');
            k = 0;
        }
    } while (k < 1 || k > kmax);

    while (getchar() != '\n'); 

    for (int i = 0; i < k; i++) {
        printf("Введите строку %d (макс длина %d): ", i + 1, lmax - 1);
        if (fgets(a[i], lmax, stdin) != NULL) {
            size_t len = strlen(a[i]);
            if (len > 0 && a[i][len - 1] == '\n') a[i][len - 1] = '\0';
        }
    }

    puts("\nЛабораторная работа №3 Леонтьев Сергей БИТ251\n");

    puts("Задание №1 (6):");
    char sub[kmax][lmax];
    int k1 = substring_search(a, sub, k);
    for (int i = 0; i < k1; i++) {
        printf("%s\n", sub[i]);
    }

    puts("\nЗадание №2 (4):");
    char res[lmax];
    ogr(sub, k1, res);
    if (res[0] != '\0') {
        printf("%s\n", res);
    } else {
        printf("Ошибка: не найдено.\n");
    }

    puts("\nЗадание №3 (1):");
    char str_old[lmax], new_str[lmax];
    if (res[0] != '\0') {
        find_old_str(a, k, str_old, res);
        update_string(str_old, new_str);
        if (new_str[0] != '\0') {
            printf("%s\n", new_str);
        } else {
            printf("Ошибка: нет подстрок.\n");
        }
    }

    return 0;
}
