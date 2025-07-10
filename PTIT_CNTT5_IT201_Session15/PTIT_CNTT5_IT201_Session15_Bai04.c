#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
}

bool isEmpty(Queue *q) {
    return q->front > q->rear;
}

void viewQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->arr[i]);
    }
}

int main() {
    Queue q1;
    initQueue(&q1, 5);

    viewQueue(&q1);

    Queue q2;
    initQueue(&q2, 5);
    q2.arr[0] = 1;
    q2.arr[1] = 2;
    q2.arr[2] = 5;
    q2.rear = 2;

    viewQueue(&q2);

    return 0;
}
