#include <stdio.h>

typedef struct Stack {
    int data[5];
    int top;
} Stack;

void createStack(Stack *s) {
    s->top = -1;
}

int main() {
    Stack myStack;
    createStack(&myStack);

    printf("Stack duoc khoi tao. Top = %d\n", myStack.top);
    return 0;
}
