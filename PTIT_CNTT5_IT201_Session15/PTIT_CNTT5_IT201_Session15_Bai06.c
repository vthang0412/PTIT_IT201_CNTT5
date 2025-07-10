#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct Queue {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enQueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int deQueue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

bool isIncreasingByOne(Queue *q) {
    if (q->rear - q->front < 1) {
        return true;
    }

    int prev = deQueue(q);
    while (!isEmpty(q)) {
        int curr = deQueue(q);
        if (curr - prev != 1) {
            return false;
        }
        prev = curr;
    }

    return true;
}

int main() {
    int n;
    printf("Nhap so luong:");
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    int x;
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        enQueue(&q, x);
    }
    if (isIncreasingByOne(&q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
