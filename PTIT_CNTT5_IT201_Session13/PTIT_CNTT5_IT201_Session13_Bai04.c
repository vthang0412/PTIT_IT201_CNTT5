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
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Khong co phan tu nao\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
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

void viewStackLIFO(Stack *s) {
    if (s->top == -1) {
        printf("Stack dang trong.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    Stack myStack;
    createStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    printStack(&myStack);

    printf("\nToan bo phan tu (LIFO):\n");
    viewStackLIFO(&myStack);

    return 0;
}

