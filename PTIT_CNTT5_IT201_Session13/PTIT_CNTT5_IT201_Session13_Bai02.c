#include <stdio.h>

#define MAX 5

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void createStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top >= MAX - 1) {
        printf("Ngan xep da day! Khong the them %d\n", value);
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

void printStack(Stack *s) {
    printf("\nstack = {\n");
    printf("    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i != s->top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d\n", MAX);
    printf("}\n");
}

int main() {
    Stack myStack;
    createStack(&myStack);

    int value;
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &value);
        push(&myStack, value);
    }

    printStack(&myStack);

    return 0;
}
