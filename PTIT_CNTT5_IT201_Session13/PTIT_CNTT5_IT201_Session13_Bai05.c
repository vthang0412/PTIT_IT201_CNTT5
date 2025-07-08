#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        return -1;
    }
    return s->data[(s->top)--];
}

void reverseArray(int arr[], int n) {
    Stack s;
    createStack(&s);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, arr[MAX];

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc: ");
    printArray(arr, n);

    return 0;
}
