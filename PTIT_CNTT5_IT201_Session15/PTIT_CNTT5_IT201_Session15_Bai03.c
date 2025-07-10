#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

bool isEmpty(Queue *q) {
    return q->front > q->rear;
}

int main() {
    Queue q1 = {{}, 0, -1};
    Queue q2 = {{1, 2, 5}, 0, 2};

    if (isEmpty(&q1)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    if (isEmpty(&q2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
