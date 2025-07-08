#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

void createStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (s->top >= MAX - 1) {
        return;
    }
    s->data[++(s->top)] = value;
}

char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->data[(s->top)--];
}

bool symmetry(char str[]) {
    Stack s;
    createStack(&s);
    int len = strlen(str);
    int mid = len / 2;

    for (int i = 0; i < mid; i++) {
        push(&s, str[i]);
    }

    int start;
    if (len%2==0) {
        start=mid;
    }else {
        start=mid+1;
    }

    for (int i = start; i < len; i++) {
        if (pop(&s) != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX];

    printf("Nhap chuoi doi xung: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (symmetry(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
