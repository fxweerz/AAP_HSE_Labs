#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int value) {
    struct Node *p = malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    p->data = value;
    p->next = *top;
    *top = p;
}

void print_stack(struct Node *top) {
    if (top == NULL) {
        printf("Стек пуст\n");
        return;
    }
    printf("Стек:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

void delete_leq_x(struct Node **top, int x) {
    while (*top != NULL && (*top)->data <= x) {
        struct Node *tmp = *top;
        *top = (*top)->next;
        free(tmp);
    }

    if (*top == NULL) return;

    struct Node *cur = *top;
    while (cur->next != NULL) {
        if (cur->next->data <= x) {
            struct Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
}

void delete_between_max_min(struct Node **top) {
    if (*top == NULL || (*top)->next == NULL)
        return;

    struct Node *cur = *top;
    struct Node *first_max = *top;
    struct Node *last_min = *top;

    int max = cur->data;
    int min = cur->data;

    while (cur != NULL) {
        if (cur->data > max) {
            max = cur->data;
            first_max = cur;
        }
        if (cur->data <= min) {
            min = cur->data;
            last_min = cur;
        }
        cur = cur->next;
    }

    if (first_max == last_min)
        return;

    struct Node *start = first_max->next;
    struct Node *end = last_min;

    while (start != NULL && start != end) {
        struct Node *tmp = start;
        start = start->next;
        free(tmp);
    }

    first_max->next = last_min;
}

void clear_stack(struct Node **top) {
    while (*top != NULL) {
        struct Node *tmp = *top;
        *top = (*top)->next;
        free(tmp);
    }
}

int main() {
    struct Node *stack = NULL;
    int value, x, f_err, f_err2;

    printf("Введите числа, каждое с новой строки(0 — конец ввода):\n");
    while (1) {
        f_err = scanf("%d", &value);
        char chr = getchar();
        while(chr!='\n') {
            if (48 > (int)chr || (int)chr > 57)
                f_err2 = 1;
            chr = getchar();
        }
        if (f_err != 1 || f_err2 == 1){
            printf("\nОшибка: некорректное значение, попробуйте снова.\n");
            continue;
        }
        if (value == 0) break;
        push(&stack, value);
    }

    print_stack(stack);

    printf("Введите X: ");
    scanf("%d", &x);
    delete_leq_x(&stack, x);

    printf("После удаления элементов <= X:\n");
    print_stack(stack);

    delete_between_max_min(&stack);

    printf("После удаления элементов между первым max и последним min:\n");
    print_stack(stack);

    clear_stack(&stack);
    return 0;
}