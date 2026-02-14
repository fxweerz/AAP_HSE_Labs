#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define lmax 51
#define kmax 10

int utf8_len(unsigned char c) {
    if (c < 128) return 1;
    return 2; 
}

int substring_search(char a[kmax][lmax], char sub[kmax][lmax], int k) {
    int ksub = 0, last_ksub = 0;

    for (int i = 0; i < k; i++) {

        last_ksub = ksub;
        char *str = a[i];

        int len = 0;
        while (str[len] != '\0') len += utf8_len((unsigned char)str[len]);

        for (int j = 0; j < len; j += utf8_len((unsigned char)str[j])) {
            if ((unsigned char)str[j] >= 192 && (unsigned char)str[j] <= 255) {

                for (int j1 = j + utf8_len((unsigned char)str[j]); 
                     j1 < len; 
                     j1 += utf8_len((unsigned char)str[j1])) 
                {
                    if ((unsigned char)str[j1] >= 192 && (unsigned char)str[j1] <= 255) {

                        int mid_start = j + utf8_len((unsigned char)str[j]);
                        int mid_len = j1 - mid_start;
                        if (mid_len <= 0) continue;
                        char flag[lmax] = {0};
                        int flag1 = 1;
                        memcpy(flag, &str[mid_start], mid_len);
                        for(int m = 0; m < ksub; m++){
                            if (strcmp(flag, sub[m]) == 0){
                                flag1 = 0;
                                break;
                            }
                        }
                        if (flag1) {
                            memcpy(sub[ksub], &str[mid_start], mid_len);
                            sub[ksub][mid_len] = '\0';
                            ksub++;
                        }
                    }
                }
            }
        }
    }
    return ksub;
}



void first_numbs(char a[kmax][lmax], int k, char res[lmax]) {
    res[0] = '\0';
    for (int i = 0; i < k; i++) {
        int count = 0;
        char *str = a[i];
        int len = 0; while (str[len] != '\0') len += utf8_len((unsigned char)str[len]);
        str = a[i];
        while (*str >= '0' && *str <= '9') {
            count++;
            str++;
        }
        if (count > 0 && count % 2 == 0) {
            memcpy(res, a[i], len);
            res[count] = '\0';
            return;
        }
    }
}

void find_old_str(char a[kmax][lmax], int k, char str_old[lmax], char sub[lmax]) {
    int len = 0;
    while (sub[len] != '\0') len += utf8_len((unsigned char)sub[len]);
    for (int i = 0; i < k; i++) {
        int flag = 0;
        int str_len = 0;
        while (a[i][str_len] != '\0') str_len += utf8_len((unsigned char)a[i][str_len]);
        for (int j = 0; j < str_len - len + 1; j += len) {
            if (strncmp(&a[i][j], sub, len) == 0) {
                flag = 1;
                memcpy(str_old, a[i], str_len);
                str_old[str_len] = '\0';
                break;
            }
        }
    }
}

void update_string(char str[lmax], char new_str[2*lmax]){
    int len = 0;
    while (str[len] != '\0') len += utf8_len((unsigned char)str[len]);
    int new_len = 0;
    for (int i = 0; i < len; i += utf8_len((unsigned char)str[i])) {
        switch (str[i]) {
            case '1':
                new_str[new_len++] = str[i];
                new_str[new_len++] = '0';
                break;
            default:
            {
                int ulen = utf8_len((unsigned char)str[i]);
                for (int k = 0; k < ulen; k++) {
                    new_str[new_len++] = str[i + k];
                }
                break;
            }
        }
    }
    new_str[new_len] = '\0';
}



int main(){
    setlocale(LC_ALL, "Russian");
    char a[kmax][lmax];
    int f_err, f_err2, k;
    do{
        printf("Введите колличество строк от 1 до %d:", kmax);
        f_err = scanf("%d", &k);
        f_err2 = 0;
        char chr = getchar();
        while(chr!='\n') {
            if (48 > (int)chr || (int)chr > 57)
                f_err2 = 1;
            chr = getchar();
        }
        if (k <= 0 || k > kmax || f_err != 1 || f_err2 == 1) {
            printf("\nОшибка: некорректное колличество строк, попробуйте снова.\n");
        }
    } while (k <= 0 || k > kmax || f_err != 1 || f_err2 == 1);
    for(int i = 0; i < k; i++){
        printf("Введите строку %d (макс. длина %d символов): ", i + 1, lmax - 1);
        do {
            f_err2 = 0;
            if (fgets(a[i], lmax, stdin) == NULL) {
                f_err2 = 1;
            } else {
                int len = 0;
                while (a[i][len] != '\0' && a[i][len] != '\n') {
                    len++;
                }
                if (len == lmax - 1 && a[i][len] != '\n') {
                    f_err2 = 1;
                    char chr;
                    while ((chr = getchar()) != '\n' && chr != EOF);
                }
            }
            if (f_err2 == 1) {
                printf("\nОшибка: некорректная строка или превышена максимальная длина, попробуйте снова.\n");
            }
        } while (f_err2 == 1);
    }
    puts("Лабораторная работа №3 Леонтьев Сергей БИТ251\n");

    puts("\nЗадание №1 (7)");
    char sub[kmax][lmax];
    int k1 = substring_search(a, sub, k);
    for (int i = 0; i < k1; i++) {
        if (sub[i][0] != '\0') {
            printf("%s\n", sub[i]);
        }
    }
    
    puts("\nЗадание №2 (9)");
    char res[lmax];
    first_numbs(sub, k1, res);
    if (res[0] != '\0') {
        printf("Подстрока начинающуюся с четного (но не нулевого) числа цифр: %s\n", res);
    } else {
        printf("Ошибка: нет первых цифр в строках.\n");
    }

    puts("\nЗадание №3 (8)");
    char str_old[lmax], new[lmax];
    if (res[0] != '\0')
        find_old_str(a, k, str_old, res);
        update_string(str_old, new);
        if (new[0] != '\0')
            printf("Обновленная строка: %s\n", new);
        else
            printf("Ошибка: нет подстрок.\n");
    return 0;
}