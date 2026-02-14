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

void insert_ap(struct Node *top, int A1) {
    struct Node *cur = top;

    while (cur != NULL) {
        if (cur->data > 0) {
            struct Node *p = malloc(sizeof(struct Node));
            if (p == NULL) return;

            p->data = A1;
            p->next = cur->next;
            cur->next = p;

            cur = p->next;
        } else {
            cur = cur->next;
        }
    }
}


void sort_afp(struct Node *top) {
    if (top == NULL) return;

    struct Node *start = top;
    while (start != NULL && start->data <= 0) {
        start = start->next;
    }
    if (start == NULL || start->next == NULL)
        return;

    int swapped;
    struct Node *end = NULL;

    do {
        swapped = 0;
        struct Node *cur = start->next;

        while (cur->next != end) {
            if (cur->data < cur->next->data) {
                int tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = 1;
            }
            cur = cur->next;
        }
        end = cur;
    } while (swapped);
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
    int value, A1;

    printf("Введите числа (0 — конец ввода):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        push(&stack, value);
    }

    print_stack(stack);

    printf("Введите A1: ");
    scanf("%d", &A1);

    insert_ap(stack, A1);
    printf("\nПосле вставки A1 после каждого положительного:\n");
    print_stack(stack);

    sort_afp(stack);
    printf("\nПосле сортировки по убыванию после первого положительного:\n");
    print_stack(stack);

    clear_stack(&stack);
    return 0;
}